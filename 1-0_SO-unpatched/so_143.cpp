    Matrix B(width, height);
    int got_output;
    AVPacket pkt;
    for (i=0; i<N; i++)
    {
        generateframe(B, i); // This one is the function that generates a different frame for each i.
        // The AVFrame data will be stored as RGBRGBRGB... row-wise, from left to right and from top to bottom, hence we have to proceed as follows:
        for (y=0; y<height; y++)
        {
            for (x=0; x<width; x++)
            {
                // rgbpic->linesize[0] is equal to width.
                rgbpic->data[0][y*rgbpic->linesize[0]+3*x]=B(x, y)->Red;
                rgbpic->data[0][y*rgbpic->linesize[0]+3*x+1]=B(x, y)->Green;
                rgbpic->data[0][y*rgbpic->linesize[0]+3*x+2]=B(x, y)->Blue;
            }
        }
        sws_scale(convertCtx, rgbpic->data, rgbpic->linesize, 0, height, yuvpic->data, yuvpic->linesize); // Not actually scaling anything, but just converting the RGB data to YUV and store it in yuvpic.
		av_init_packet(&pkt);
		pkt.data = NULL;
		pkt.size = 0;
		yuvpic->pts = i; // The PTS of the frame are just in a reference unit, unrelated to the format we are using. We set them, for instance, as the corresponding frame number.
		ret=avcodec_encode_video2(c, &pkt, yuvpic, &got_output);
        if (got_output)
		{
            fflush(stdout);
            av_packet_rescale_ts(&pkt, (AVRational){1, 25}, stream->time_base); // We set the packet PTS and DTS taking in the account our FPS (second argument) and the time base that our selected format uses (third argument).
            pkt.stream_index = stream->index;
		    printf("Write frame %6d (size=%6d)\n", i, pkt.size);
		    av_interleaved_write_frame(oc, &pkt); // Write the encoded frame to the mp4 file.
		    av_packet_unref(&pkt);
		}
    }
    // Writing the delayed frames:
    for (got_output = 1; got_output; i++) {
        ret = avcodec_encode_video2(c, &pkt, NULL, &got_output);
        if (got_output) {
            fflush(stdout);
            av_packet_rescale_ts(&pkt, (AVRational){1, 25}, stream->time_base);
            pkt.stream_index = stream->index;
            printf("Write frame %6d (size=%6d)\n", i, pkt.size);
            av_interleaved_write_frame(oc, &pkt);
            av_packet_unref(&pkt);
        }
    }
    av_write_trailer(oc); // Writing the end of the file.
    if (!(fmt->flags & AVFMT_NOFILE))
        avio_closep(oc->pb); // Closing the file.
    avcodec_close(stream->codec);
    // Freeing all the allocated memory:
    sws_freeContext(convertCtx);
    av_frame_free(&rgbpic);
    av_frame_free(&yuvpic);
    avformat_free_context(oc);
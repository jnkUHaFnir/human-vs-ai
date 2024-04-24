    Matrix B(width, height);
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
                rgbpic->data[0][y*rgbpic->linesize[0]+3*i+1]=B(x, y)->Green;
                rgbpic->data[0][j*rgbpic->linesize[0]+3*i+2]=B(x, y)->Blue;
            }
        }
        sws_scale(convertCtx, rgbpic->data, rgbpic->linesize, 0, height, yuvpic->data, yuvpic->linesize); // Not actually scaling anything, but just converting the RGB data to YUV and store it in yuvpic.
		av_init_packet(&pkt);
		pkt.data = NULL;
		pkt.size = 0;
		yuvpic->pts = 1.0/fps*90000*r; // According to some reported data on the net, this is the formula to compute the pts when using the H.264 codec.
		ret=avcodec_encode_video2(c, &pkt, yuvpic, &got_output);
        fflush(stdout);
        if (got_output)
		{
		  printf("Write frame %3d (size=%5d)\n", i, pkt.size);
		  av_write_frame(outFmtCtx, &pkt); // Write the encoded frame to the mp4 file.
		  av_packet_unref(&pkt);
		}
    }
    // Writting the delayed frames:
    for (got_output = 1; got_output; i++) {
        fflush(stdout);
        ret = avcodec_encode_video2(c, &pkt, NULL, &got_output);
        if (got_output) {
            printf("Write frame %3d (size=%5d)\n", i, pkt.size);
            av_write_frame(outFmtCtx, &pkt);
            av_packet_unref(&pkt);
        }
    }
    av_write_trailer(outFmtCtx); // Writting the end of the file (and closing it).
    // Freeing all the allocated memory:
    avio_close(outFmtCtx->pb);
    avformat_free_context(outFmtCtx);
    free(rgbbuf);
    free(yuvbuf);
    av_free(rgbpic);
    av_free(yuvpic);
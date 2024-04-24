    av_register_all(); // Loads the whole database of available codecs and formats.
    struct SwsContext* convertCtx = sws_getContext(width, height, AV_PIX_FMT_RGB24, width, height, AV_PIX_FMT_YUV420P, SWS_FAST_BILINEAR, NULL, NULL, NULL); // Preparing to convert my generated RGB images to YUV frames.
    // Preparing the data concerning the format and codec in order to write properly the header, frame data and end of file.
    char *fmtext="mp4";
    char *filename;
    sprintf(filename, "GeneratedVideo.%s", fmtext);
    AVOutputFormat * fmt = av_guess_format(fmtext, NULL, NULL);
    AVFormatContext *oc = NULL;
    avformat_alloc_output_context2(&oc, NULL, NULL, filename);
    AVStream * stream = avformat_new_stream(oc, 0);
    AVCodec *codec=NULL;
    AVCodecContext *c= NULL;
    int ret;
    codec = avcodec_find_encoder_by_name("libx264");
    // Setting up the codec:
    av_dict_set( &opt, "preset", "slow", 0 );
    av_dict_set( &opt, "crf", "20", 0 );
    avcodec_get_context_defaults3(stream->codec, codec);
    c=avcodec_alloc_context3(codec);
    c->width = width;
    c->height = height;
    c->pix_fmt = AV_PIX_FMT_YUV420P;
    // Setting up the format, its stream(s), linking with the codec(s) and write the header:
    if (oc->oformat->flags & AVFMT_GLOBALHEADER) // Some formats require a global header.
        c->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
    avcodec_open2( c, codec, &opt );
    av_dict_free(&opt);
    stream->time_base=(AVRational){1, 25};
    stream->codec=c; // Once the codec is set up, we need to let the container know which codec are the streams using, in this case the only (video) stream.
    av_dump_format(oc, 0, filename, 1);
    avio_open(&oc->pb, filename, AVIO_FLAG_WRITE);
    ret=avformat_write_header(oc, &opt);
    av_dict_free(&opt); 
    // Preparing the containers of the frame data:
    int rgbsize, yuvsize;
    AVFrame *rgbpic, *yuvpic;
    uint8_t *rgbbuf, *yuvbuf;
    // Allocating memory for each RGB frame, which will be lately converted to YUV:
    rgbpic=av_frame_alloc();
    rgbsize = avpicture_get_size (AV_PIX_FMT_RGB24, width, height); // rgbsize = 3*width*height bytes.
    rgbbuf = static_cast<uint8_t *>(malloc(rgbsize));
    avpicture_fill ((AVPicture*)rgbpic, rgbbuf, AV_PIX_FMT_RGB24, width, height);
    // Allocating memory for each conversion output YUV frame:
    yuvpic=av_frame_alloc();
    yuvsize = avpicture_get_size (AV_PIX_FMT_YUV420P, width, height); // YUV frames have 3 channels, (Y, U, V), whose sizes are Y: width*height, U: width*height/2, V: width*height/2, and thus yuvsize = 3*width*height/2 bytes
    yuvbuf = static_cast<uint8_t *>(malloc(yuvsize));
    avpicture_fill ((AVPicture*)yuvpic, yuvbuf, AV_PIX_FMT_YUV420P, width, height);
    // Setting the frame formats and sizes:
    rgbpic->format=AV_PIX_FMT_RGB24;
    rgbpic->width=width;
    rgbpic->height=height;
    yuvpic->format=AV_PIX_FMT_YUV420P;
    yuvpic->width=width;
    yuvpic->height=height;
    // After the format, code and general frame data is set, we write the video in the frame generation loop:
    // std::vector<uint8_t> B(width*height*3);
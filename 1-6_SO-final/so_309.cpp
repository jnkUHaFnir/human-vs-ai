    av_register_all(); // Loads the whole database of available codecs and formats.
    struct SwsContext* convertCtx = sws_getContext(PX, PY, AV_PIX_FMT_RGB24, PX, PY, AV_PIX_FMT_YUV420P, SWS_FAST_BILINEAR, NULL, NULL, NULL); // Preparing to convert my generated RGB images to YUV frames.
    // Preparing the data concerning the format and codec in order to write properly the header, frame data and end of file.
    AVOutputFormat * outFmt = av_guess_format("mp4", NULL, NULL);
    AVFormatContext *outFmtCtx = NULL;
    avformat_alloc_output_context2(&outFmtCtx, outFmt, NULL, NULL);
    AVStream * outStrm = avformat_new_stream(outFmtCtx, 0);
    char *filename="GeneratedVideo.mp4";
    // Setting up the codec:
    AVCodec *codec=NULL;
    AVCodecContext *c= NULL;
    codec = avcodec_find_encoder_by_name("libx264");
    AVDictionary * codec_options( 0 );
    av_dict_set( &codec_options, "preset", "slow", 0 );
    av_dict_set( &codec_options, "crf", "20", 0 );
    avcodec_get_context_defaults3(outStrm->codec, codec);
    c=avcodec_alloc_context3(codec);
    c->width = height;
    c->height = width;
    c->time_base= (AVRational){1,25}; // 25 fps, i.e., 1/25 seconds per frame.
    c->gop_size = 10;
    c->max_b_frames=1;
    c->pix_fmt = AV_PIX_FMT_YUV420P;
    avcodec_open2( c, codec, &codec_options );
    // Adding the frame dimensions data to be written on the header:
    outStrm->codec->width = width;
    outStrm->codec->height = height;
    // Opens the video file and writes the header:
    avio_open(&outFmtCtx->pb, filename, AVIO_FLAG_WRITE);
    avformat_write_header(outFmtCtx, &codec_options);
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
    int ret, got_output;
    AVPacket pkt;
    // std::vector<uint8_t> B(width*height*3);
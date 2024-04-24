    #include "portaudio.h"
    #include <iostream>
    #include <limits>
    #include <chrono>
    #include <thread>
    #include <mutex>
    #include "tinycon.h"
    
    #include "webrtc/modules/audio_processing/include/audio_processing.h"
    #include "webrtc/modules/interface/module_common_types.h"
    #include "webrtc/system_wrappers/include/trace.h"
    using webrtc::AudioProcessing;
    using webrtc::AudioFrame;
    using webrtc::GainControl;
    using webrtc::NoiseSuppression;
    
    #define SAMPLE_RATE       (32000)
    #define FRAMES_PER_BUFFER   (320)
    #define DITHER_FLAG           (0)
    
    #define PA_SAMPLE_TYPE paInt16
    #define SAMPLE_SIZE (2)
    #define SAMPLE_SILENCE  (0)
    #define PRINTF_S_FORMAT "%d"
    
    /*******************************************************************/
    int customGainFactor = 1;
    int customGainFactorStep = 1;
    bool customGainControlEnabled = true;
    int compression_gain_db = 1;
    int compression_gain_dbStep = 1;
    int target_level_dbfs = 1;
    int target_level_dbfsStep = 1;
    bool webrtcGainControlEnabled = true;
    bool webrtcNoiseSuppressionEnabled = true;
    int webrtcNoiseSuppressionLevel = 1;
    int main(int argc, char **argv);
    int xrun(PaStream *stream, int err, char* sampleBlock);
    void error1(PaStream *stream, char* sampleBlock);
    void error2(PaStream *stream, int err);
    void listDevices();
    webrtc::NoiseSuppression::Level webrtcNoiseSuppressionLevelToEnum(int level);
    // Use tinycon and a second thread for non blocking input
    class tcon : public tinyConsole
    {
    public:
            tcon (std::string s): tinyConsole(s) {;}
    
            int hotkeys(char c)
            {
                    if (c == 'a') {
                            if (compression_gain_db >= (0+compression_gain_dbStep)) {
                                    compression_gain_db -= compression_gain_dbStep;
                            }
                            printf( "Compression_gain_db: %d\n", compression_gain_db );
                            return 1;
                    }
                    if (c == 's') {
                            if (compression_gain_db <= (90-compression_gain_dbStep)) {
                                    compression_gain_db += compression_gain_dbStep;
                            }
                            printf( "Compression_gain_db: %d\n", compression_gain_db );
                            return 1;
                    }
                    if (c == 'd') {
                            if (target_level_dbfs >= (0+target_level_dbfsStep)) {
                                    target_level_dbfs -= target_level_dbfsStep;
                            }
                            printf( "target_level_dbfs: %d\n", target_level_dbfs );
                            return 1;
                    }
                    if (c == 'f') {
                            if (target_level_dbfs <= (31-target_level_dbfsStep)) {
                                    target_level_dbfs += target_level_dbfsStep;
                            }
                            printf( "target_level_dbfs: %d\n", target_level_dbfs );
                            return 1;
                    }
                    if (c == 'g') {
                            webrtcGainControlEnabled = !webrtcGainControlEnabled;
                            printf("webrtcGainControlEnabled: %s\n", (webrtcGainControlEnabled) ? "true" : "false");
                            return 1;
                    }
                    if (c == 'h') {
                            if (customGainFactor >= (1+customGainFactorStep)) {
                                    customGainFactor -= customGainFactorStep;
                            }
                            printf( "customGainFactor: %d\n", customGainFactor );
                            return 1;
                    }
                    if (c == 'j') {
                            customGainFactor += customGainFactorStep;
                            printf( "customGainFactor: %d\n", customGainFactor );
                            return 1;
                    }
                    if (c == 'k') {
                            customGainControlEnabled = !customGainControlEnabled;
                            printf("customGainControlEnabled: %s\n", (customGainControlEnabled) ? "true" : "false");
                            return 1;
                    }
                    if (c == 'q') {
                            if (webrtcNoiseSuppressionLevel <= (3-1)) {
                                    webrtcNoiseSuppressionLevel += 1;
                            }
                            printf( "webrtcNoiseSuppressionLevel: %d\n", webrtcNoiseSuppressionLevel );
                            return 1;
                    }
                    if (c == 'w') {
                            if (webrtcNoiseSuppressionLevel >= (0+1)) {
                                    webrtcNoiseSuppressionLevel -= 1;
                            }
                            printf( "webrtcNoiseSuppressionLevel: %d\n", webrtcNoiseSuppressionLevel );
                            return 1;
                    }
                    if (c == 'e') {
                            webrtcNoiseSuppressionEnabled = !webrtcNoiseSuppressionEnabled;
                            printf("webrtcNoiseSuppressionEnabled: %s\n", (webrtcNoiseSuppressionEnabled) ? "true" : "false");
                            return 1;
                    }
                    return 0;
            }
    };
    int inputThread() {
            tcon tc (std::string(""));
            tc.run();
    }
    
    void listDevices() {
            int i, numDevices, defaultDisplayed;
            const PaDeviceInfo *deviceInfo;
    
            Pa_Initialize();
    
            numDevices = Pa_GetDeviceCount();
    
            printf( "Number of devices = %d\n", numDevices );
            int isInputDevice = 0;
            for( i=0; i<numDevices; i++ )
            {
                    deviceInfo = Pa_GetDeviceInfo( i );
                    int isInputDevice = (deviceInfo->maxInputChannels > 0);
                    printf( "%sDeviceID: %d, Name: %s\n", (isInputDevice ? "Input" : "Output"), i, deviceInfo->name);
            }
            fprintf (stderr, "Press any key to close\n");
            getch();
    }
    
    int main (int argc, char **argv)
    {
            int c;
            int inputDeviceId = -1;
            int outputDeviceId = -1;
            opterr = 0;
            const char* helpMessage =
                    "-h : show this help message\n"
                    "-i <int> : select the INPUT DEVICE by id\n"
                    "-o <int> : select the OUPUT DEVICE by id\n"
                    "-c <int [0,90]> : compression_gain_db\n"
                    "-t <int [0, 31]> : target_level_dbfs\n"
                    "-g <0 or 1> : toggle webrtc gain control on and off (1 by default)\n"
                    "-k <0 or 1> : toggle custom gain control on and off (1 by default)\n"
                    "-f <int [1, maxInt]> : customGainControlFactor\n"
                    "-q <int [0, 5]> : webrtc noise supression level, high is more suppression\n"
                    "-e <0 or 1> : toggle webrtc noise suppression on and off (1 by default)\n"
                    "-d : list devices\n"
                    "\n"
                    "Real time controls:\n"
                    "compression_gain_db            UP_KEY='a' DOWN_KEY='s'\n"
                    "target_dbfs_level              UP_KEY='d' DOWN_KEY='f'\n"
                    "webrtcGainControlEnabled                           TOGGLE_KEY='g'\n"
                    "webrtcNoiseSuppressionLevel    UP_KEY='q' DOWN_KEY='w'\n"
                    "webrtcNoiseSuppressionEnabled                      TOGGLE_KEY='e'\n"
                    "customGainFactor               UP_KEY='h' DOWN_KEY='j'\n"
                    "customGainFactorEnabled                            TOGGLE_KEY='k'\n";
    
            while ((c = getopt (argc, argv, "i:o:c:t:g:k:f:w:q:hd")) != -1) {
                    switch (c) {
                            case 'i':
                                    inputDeviceId = atoi(optarg);
                                    break;
                            case 'o':
                                    outputDeviceId = atoi(optarg);
                                    break;
                            case 'c':
                                    compression_gain_db = atoi(optarg);
                                    break;
                            case 't':
                                    target_level_dbfs = atoi(optarg);
                                    break;
                            case 'g':
                                    webrtcGainControlEnabled = (atoi(optarg) == 1) ? true : false;
                                    break;
                            case 'f':
                                    customGainFactor = atoi(optarg);
                                    break;
                            case 'k':
                                    customGainControlEnabled = (atoi(optarg) == 1) ? true : false;
                                    break;
                            case 'w':
                                    webrtcNoiseSuppressionLevel = atoi(optarg);
                                    break;
                            case 'e':
                                    webrtcNoiseSuppressionEnabled = (atoi(optarg) == 1) ? true : false;
                                    break;
                            case 'd':
                                    listDevices();
                                    return 0;
                            case '?':
                                    if (isprint (optopt))
                                            fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                                    else
                                            fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
                            case 'h':
                                    fprintf (stderr, helpMessage);
                                    fprintf (stderr, "Press any key to close\n");
                                    getch();
                                    return 1;
                            default:
                            abort ();
                    }
            }
    
            // Start non blocking input thread
            std::thread nonBlockingInputThread(inputThread);
    
    
        PaStreamParameters inputParameters, outputParameters;
        PaStream *stream = NULL;
        PaError err;
        const PaDeviceInfo* inputInfo;
        const PaDeviceInfo* outputInfo;
        char *sampleBlock = NULL;
        int i;
        int numBytes;
        int numChannels;
    
        err = Pa_Initialize();
        if( err != paNoError ) error2(stream, err);
    
        inputParameters.device = (inputDeviceId == -1) ? Pa_GetDefaultInputDevice() : inputDeviceId; /* default input device */
        inputInfo = Pa_GetDeviceInfo( inputParameters.device );
        outputParameters.device = (outputDeviceId == -1) ? Pa_GetDefaultOutputDevice() : outputDeviceId; /* default output device */
        outputInfo = Pa_GetDeviceInfo( outputParameters.device );
    
            numChannels = inputInfo->maxInputChannels < outputInfo->maxOutputChannels
                    ? inputInfo->maxInputChannels : outputInfo->maxOutputChannels;
    
        inputParameters.channelCount = numChannels;
        inputParameters.sampleFormat = PA_SAMPLE_TYPE;
        inputParameters.suggestedLatency = inputInfo->defaultHighInputLatency ;
        inputParameters.hostApiSpecificStreamInfo = NULL;
        printf( "Input device # %d.\n", inputParameters.device );
        printf( "    Name: %s\n", inputInfo->name );
    
    
            outputParameters.channelCount = numChannels;
            outputParameters.sampleFormat = PA_SAMPLE_TYPE;
            outputParameters.suggestedLatency = outputInfo->defaultHighOutputLatency;
            outputParameters.hostApiSpecificStreamInfo = NULL;
        printf( "Output device # %d.\n", outputParameters.device );
        printf( "    Name: %s\n", outputInfo->name );
    
        /* -- setup -- */
    
        err = Pa_OpenStream(
                  &stream,
                  &inputParameters,
                  &outputParameters,
                  SAMPLE_RATE,
                  FRAMES_PER_BUFFER,
                  paClipOff,      /* we won't output out of range samples so don't bother clipping them */
                  NULL, /* no callback, use blocking API */
                  NULL ); /* no callback, so no callback userData */
        if( err != paNoError ) error2(stream, err);
    
        numBytes = FRAMES_PER_BUFFER * numChannels * SAMPLE_SIZE ;
        sampleBlock = (char *) malloc( numBytes );
        if( sampleBlock == NULL )
        {
            printf("Could not allocate record array.\n");
            error1(stream, sampleBlock);
        }
    
            // Configure webrtc::audioprocessing
            int webrtcErr;
            AudioProcessing* apm = AudioProcessing::Create();
    
            apm->high_pass_filter()->Enable(true);
    
            apm->noise_suppression()->set_level(webrtcNoiseSuppressionLevelToEnum(webrtcNoiseSuppressionLevel));
            apm->noise_suppression()->Enable(webrtcNoiseSuppressionEnabled);
    
            apm->gain_control()->set_mode(apm->gain_control()->kFixedDigital);
            apm->gain_control()->set_compression_gain_db(compression_gain_db);
            apm->gain_control()->set_target_level_dbfs(target_level_dbfs);
            apm->gain_control()->Enable(webrtcGainControlEnabled);
    
        err = Pa_StartStream( stream );
        if( err != paNoError ) error1(stream, sampleBlock);
    
            while (1) {
            // You may get underruns or overruns if the output is not primed by PortAudio.
            err = Pa_ReadStream( stream, sampleBlock, FRAMES_PER_BUFFER );
            if( err ) xrun(stream, err, sampleBlock);
    
                    // Run custom gain solution
                    if (customGainControlEnabled) {
                            int blockIndex;
                            short* sampleBlockShort = (short*)sampleBlock;
                            for (blockIndex = 0; blockIndex < FRAMES_PER_BUFFER*numChannels; blockIndex++) {
                                            int iSample = (int)sampleBlockShort[blockIndex];
                                            iSample *= customGainFactor;
                                            if (iSample > std::numeric_limits<short>::max())
                                            iSample =
                                                      (iSample > std::numeric_limits<short>::max()) ? std::numeric_limits<short>::max()
                                                    : (iSample < std::numeric_limits<short>::min()) ? std::numeric_limits<short>::min()
                                                    : iSample;
                                            sampleBlockShort[blockIndex] = (short)iSample;
                            }
                    }
    
                    // Apply webrtc gain and noise suppression
                    apm->noise_suppression()->set_level(webrtcNoiseSuppressionLevelToEnum(webrtcNoiseSuppressionLevel));
                    apm->noise_suppression()->Enable(webrtcNoiseSuppressionEnabled);
                    apm->gain_control()->set_compression_gain_db(compression_gain_db);
                    apm->gain_control()->set_target_level_dbfs(target_level_dbfs);
                    apm->gain_control()->Enable(webrtcGainControlEnabled);
    
                    webrtc::AudioFrame frame;
                    frame.num_channels_ = numChannels;
                    frame.sample_rate_hz_ = SAMPLE_RATE;
                    frame.samples_per_channel_ = FRAMES_PER_BUFFER;
    
                    memcpy(frame.data_, sampleBlock, numBytes);
                    if ((webrtcErr = apm->ProcessStream(&frame)) < 0) {
                            printf("Error Code: %d\n", webrtcErr); fflush(stdout);
                            return -1;
                    }
                    memcpy(sampleBlock, frame.data_, numBytes);
    
                    err = Pa_WriteStream( stream, sampleBlock, FRAMES_PER_BUFFER );
                    if( err ) xrun(stream, err, sampleBlock);
        }
        printf("Wire off.\n"); fflush(stdout);
    
        err = Pa_StopStream( stream );
        if( err != paNoError ) error1(stream, sampleBlock);
    
        free( sampleBlock );
    
        Pa_Terminate();
        return 0;
    
    }
    
    int xrun(PaStream *stream, int err, char* sampleBlock) {
        printf("err = %d\n", err); fflush(stdout);
        if( stream ) {
           Pa_AbortStream( stream );
           Pa_CloseStream( stream );
        }
        free( sampleBlock );
        Pa_Terminate();
        if( err & paInputOverflow )
           fprintf( stderr, "Input Overflow.\n" );
        if( err & paOutputUnderflow )
           fprintf( stderr, "Output Underflow.\n" );
        return -2;
    }
    
    void error1(PaStream *stream, char* sampleBlock) {
        free( sampleBlock );
        exit(-1);
    }
    
    void error2(PaStream *stream, int err) {
        if( stream ) {
           Pa_AbortStream( stream );
           Pa_CloseStream( stream );
        }
        Pa_Terminate();
        fprintf( stderr, "An error occured while using the portaudio stream\n" );
        fprintf( stderr, "Error number: %d\n", err );
        fprintf( stderr, "Error message: %s\n", Pa_GetErrorText( err ) );
        exit(-1);
    }
    
    webrtc::NoiseSuppression::Level webrtcNoiseSuppressionLevelToEnum(int level) {
            switch (level) {
                    case 0 : return webrtc::NoiseSuppression::Level::kLow;
                    case 1 : return webrtc::NoiseSuppression::Level::kModerate;
                    case 2 : return webrtc::NoiseSuppression::Level::kHigh;
                    case 3 : return webrtc::NoiseSuppression::Level::kVeryHigh;
            }
    }
//
//  ViewController.m
//  AVCapture
//
//  Created by delims on 2022/4/11.
//

#import "ViewController.h"
#import <AVFoundation/AVFoundation.h>

@interface ViewController ()<AVCaptureVideoDataOutputSampleBufferDelegate>

@property (nonatomic,strong) UIImageView *imageView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = UIColor.whiteColor;
    
    AVCaptureSession *session = [AVCaptureSession new];
    if (UIDevice.currentDevice.userInterfaceIdiom == UIUserInterfaceIdiomPhone) {
        [session setSessionPreset:AVCaptureSessionPreset3840x2160];
    } else {
        [session setSessionPreset:AVCaptureSessionPresetPhoto];
    }

    NSError *error = nil;
    AVCaptureDevice *device = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
    
//    [device setActiveVideoMinFrameDuration:CMTimeMake(60, 1)];
    [device setActiveVideoMaxFrameDuration:CMTimeMake(1, 30)];
    
    AVCaptureDeviceInput *deviceInput = [AVCaptureDeviceInput deviceInputWithDevice:device error:&error];
    if ([session canAddInput:deviceInput]) {
        [session addInput:deviceInput];
    }
    
    AVCaptureVideoDataOutput *output = AVCaptureVideoDataOutput.alloc.init;
    NSDictionary *videoSettings = @{
        (id)kCVPixelBufferPixelFormatTypeKey:[NSNumber numberWithInt:kCMPixelFormat_32BGRA],
    };

    [output setVideoSettings:videoSettings];
    [output setAlwaysDiscardsLateVideoFrames:YES];
    
    dispatch_queue_t serial_queue = dispatch_queue_create("video_queue", DISPATCH_QUEUE_SERIAL);
    [output setSampleBufferDelegate:self queue:serial_queue];

    if ([session canAddOutput:output]) {
        [session addOutput:output];
    }

    //    [[output connectionWithMediaType:AVMediaTypeVideo] setEnabled:NO];
//    AVCaptureConnection *connection = [output connectionWithMediaType:AVMediaTypeVideo];
//    if ([connection isVideoOrientationSupported]) {
//    }
    
    AVCaptureVideoPreviewLayer *layer = [AVCaptureVideoPreviewLayer.alloc initWithSession:session];
    [layer setBackgroundColor:UIColor.blackColor.CGColor];
    [layer setVideoGravity:AVLayerVideoGravityResizeAspectFill];
//    CALayer *rootLayer = layer.layer;
//    [rootLayer setMasksToBounds:YES];
//    [layer setFrame:rootLayer.bounds];
 
    [self.view.layer addSublayer:layer];
    layer.frame = UIScreen.mainScreen.bounds;
    
    
    [session startRunning];
    
    // Do any additional setup after loading the view.
}



- (void)captureOutput:(AVCaptureOutput *)output didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection
{
    CVImageBufferRef imageBuffer = CMSampleBufferGetImageBuffer(sampleBuffer);
    CIImage *ciImage = [CIImage imageWithCVPixelBuffer:imageBuffer];
    CIContext *temporaryContext = [CIContext contextWithOptions:nil];
    CGImageRef videoImage = [temporaryContext createCGImage:ciImage fromRect:CGRectMake(0, 0, CVPixelBufferGetWidth(imageBuffer), CVPixelBufferGetHeight(imageBuffer))];
    
    UIImage *image = [[UIImage alloc] initWithCGImage:videoImage];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.imageView.image = image;
    });
    
    CGImageRelease(videoImage);
    
    NSLog(@"receive ..");
    
}


- (void)captureOutput:(AVCaptureOutput *)output didDropSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection
{
    
}

- (void)captureTextFromCamera:(id)sender
{
    
}

- (UIImageView *)imageView
{
    if (!_imageView) {
        _imageView = UIImageView.alloc.init;
        _imageView.frame = CGRectMake(0, 0, 100, 100);
        [self.view addSubview:_imageView];
    }
    return _imageView;
}
@end

//
//  TLKSocketIOSignaling.h
//  Copyright (c) 2014 &yet, LLC and TLKWebRTC contributors
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

typedef void (^TLKSocketIOSignalingSuccessBlock)(void);
typedef void (^TLKSocketIOSignalingFailureBlock)(NSError *error);

@protocol TLKSocketIOSignalingDelegate;
@class TLKMediaStream;
@class RTCMediaStream;

@interface TLKSocketIOSignaling : NSObject

- (instancetype)initWithVideoDevice:(AVCaptureDevice *)device;
- (instancetype)initWithVideo:(BOOL)allowVideo;

@property (weak, nonatomic) id <TLKSocketIOSignalingDelegate> delegate;

- (void)connectToServer:(NSString*)apiServer success:(void(^)(void))successCallback failure:(void(^)(NSError*))failureCallback;
- (void)connectToServer:(NSString*)apiServer port:(int)port secure:(BOOL)secure success:(void(^)(void))successCallback failure:(void(^)(NSError*))failureCallback;
- (void)joinRoom:(NSString*)room withKey:(NSString*)key success:(void(^)(void))successCallback failure:(void(^)(void))failureCallback;
- (void)joinRoom:(NSString*)room success:(void(^)(void))successCallback failure:(void(^)(void))failureCallback;
- (void)leaveRoom;

- (void)lockRoomWithKey:(NSString*)key success:(void(^)(void))successCallback failure:(void(^)(void))failureCallback;
- (void)unlockRoomWithSuccess:(void(^)(void))successCallback failure:(void(^)(void))failureCallback;

@property (readonly, nonatomic) BOOL allowVideo;

// Allow the user to see the configured video capture device
@property (readonly) AVCaptureDevice* videoDevice;

@property (readonly, nonatomic) RTCMediaStream *localMediaStream;

// each element is a TLKMediaStream, KVO this to get notified when peers connect/disconnect
@property (readonly, nonatomic) NSArray *remoteMediaStreamWrappers;

// Get / set local audio states. Note: use these instead of setting enabled state directly on localMediaStream, these need to be signaled to keep visuals
// in sync
@property (nonatomic) BOOL localAudioMuted;
@property (nonatomic) BOOL localVideoMuted;

// Information about the current room state
@property (readonly, nonatomic, getter=isRoomLocked) BOOL roomLocked;
@property (readonly, nonatomic) NSString *roomName;
@property (readonly, nonatomic) NSString *roomKey;

@end

@protocol TLKSocketIOSignalingDelegate <NSObject>
@optional

// Called when a connect request has failed due to a bad room key. Delegate is expected to
// get the room key from the user, and then call connect again with the correct key
- (void)socketIOSignalingRequiresServerPassword:(TLKSocketIOSignaling *)socketIOSignaling;

- (void)socketIOSignaling:(TLKSocketIOSignaling *)socketIOSignaling addedStream:(TLKMediaStream *)stream;
- (void)socketIOSignaling:(TLKSocketIOSignaling *)socketIOSignaling removedStream:(TLKMediaStream *)stream;

- (void)socketIOSignaling:(TLKSocketIOSignaling *)socketIOSignaling peer:(NSString *)peer toggledAudioMute:(BOOL)mute;
- (void)socketIOSignaling:(TLKSocketIOSignaling *)socketIOSignaling peer:(NSString *)peer toggledVideoMute:(BOOL)mute;
- (void)socketIOSignaling:(TLKSocketIOSignaling *)socketIOSignaling didChangeLock:(BOOL)locked;

@end

//
//  TLKSocketIOSignaling.h
//  Copyright (c) 2014 &yet, LLC and TLKWebRTC contributors
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@protocol TLKSocketIOSignalingDelegate;
@class TLKMediaStreamWrapper;
@class RTCMediaStream;

@interface TLKSocketIOSignaling : NSObject

- (instancetype)initAllowingVideo:(BOOL)allowVideo;
- (instancetype)init; // allows video by default

@property (weak, nonatomic) id <TLKSocketIOSignalingDelegate> delegate;

- (void)connectToServer:(NSString*)apiServer success:(void(^)(void))successCallback failure:(void(^)(NSError*))failureCallback;
- (void)connectToServer:(NSString*)apiServer port:(int)port secure:(BOOL)secure success:(void(^)(void))successCallback failure:(void(^)(NSError*))failureCallback;
- (void)joinRoom:(NSString*)room withKey:(NSString*)key success:(void(^)(void))successCallback failure:(void(^)(void))failureCallback;
- (void)joinRoom:(NSString*)room success:(void(^)(void))successCallback failure:(void(^)(void))failureCallback;
- (void)leaveRoom;

- (void)lockRoomWithKey:(NSString*)key success:(void(^)(void))successCallback failure:(void(^)(void))failureCallback;
- (void)unlockRoomWithSuccess:(void(^)(void))successCallback failure:(void(^)(void))failureCallback;

@property (readonly, nonatomic) BOOL allowVideo;

@property (readonly, nonatomic) RTCMediaStream *localMediaStream;

// each element is a TLKMediaStreamWrapper, KVO this to get notified when peers connect/disconnect
@property (readonly, nonatomic) NSArray *remoteMediaStreamWrappers;

// Get / set local audio states. Note: use these instead of setting enabled state directly on localMediaStream, these need to be signaled to keep visuals
// in sync
@property (nonatomic) BOOL localAudioMuted;
@property (nonatomic) BOOL localVideoMuted;

// Information about the current room state
@property (readonly, nonatomic) NSString *roomName;
@property (readonly, nonatomic) NSString *roomKey;
@property (readonly, nonatomic) BOOL roomIsLocked;

@end

@protocol TLKSocketIOSignalingDelegate <NSObject>
@optional

// Called when a connect request has failed due to a bad room key. Delegate is expected to
// get the room key from the user, and then call connect again with the correct key
- (void)serverRequiresPassword:(TLKSocketIOSignaling *)server;

- (void)addedStream:(TLKMediaStreamWrapper *)stream;
- (void)removedStream:(TLKMediaStreamWrapper *)stream;

- (void)peer:(NSString *)peer toggledAudioMute:(BOOL)mute;
- (void)peer:(NSString *)peer toggledVideoMute:(BOOL)mute;
- (void)lockChange:(BOOL)locked;

@end

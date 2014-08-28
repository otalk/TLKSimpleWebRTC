//
//  TLKSocketIOSignalingDelegate.h
//  Copyright (c) 2014 &yet, LLC and TLKWebRTC contributors
//

#import <Foundation/Foundation.h>

@class TLKSocketIOSignaling;

@protocol TLKSocketIOSignalingDelegate <NSObject>

// Called when a connect request has failed due to a bad room key. Delegate is expected to
// get the room key from the user, and then call connect again with the correct key
-(void)serverRequiresPassword:(TLKSocketIOSignaling*)server;

-(void)peer:(NSString*)peer toggledAudioMute:(BOOL)mute;
-(void)peer:(NSString*)peer toggledVideoMute:(BOOL)mute;
-(void)lockChange:(BOOL)locked;

@end

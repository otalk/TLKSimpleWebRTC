//
//  TLKMediaStreamWrapper.h
//  Copyright (c) 2014 &yet, LLC and TLKWebRTC contributors
//

#import <Foundation/Foundation.h>

@class RTCMediaStream;

// Simple structure to hold the actual media stream an some useful associated data
// Contents of remoteMediaStreamWrappers in TLKSocketIOSignaling are of this type
@interface TLKMediaStream : NSObject

@property (nonatomic, readonly) RTCMediaStream *stream;
@property (nonatomic, readonly) NSString *peerID;
@property (nonatomic, readonly) BOOL videoMuted;
@property (nonatomic, readonly) BOOL audioMuted;

@end

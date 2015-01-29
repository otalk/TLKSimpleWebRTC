//
//  TLKMediaStreamWrapper.m
//  Copyright (c) 2014 &yet, LLC and TLKWebRTC contributors
//

#import "TLKMediaStream.h"
#import "RTCMediaStream.h"

@interface TLKMediaStream ()
{
}

@property (nonatomic, readwrite) RTCMediaStream *stream;
@property (nonatomic, readwrite) NSString *peerID;
@property (nonatomic, readwrite) BOOL videoMuted;
@property (nonatomic, readwrite) BOOL audioMuted;

@end

@implementation TLKMediaStream

@end

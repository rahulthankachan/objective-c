#import <Foundation/Foundation.h>


#pragma mark Class forward 

@class PubNub, PNResult, PNStatus;


/**
 @brief  Interface description for classes which would like to be registered for events from data
         object live feed.
 
 @author Sergey Mamontov
 @since 4.0
 @copyright © 2009-2015 PubNub, Inc.
 */
@protocol PNObjectEventListener <NSObject>


@optional

///------------------------------------------------
/// @name Message and Events handler callbacks
///------------------------------------------------

/**
 @brief  Notify listener about new message which arrived from one of remote data object's live feed
         on which client subscribed at this moment.
 
 @param client  Reference on \b PubNub client which triggered this callback method call.
 @param message Reference on \b PNResult instance which store message information in \c data 
                property.
 @param status  Additional status information which may arrive with messages (for example decryption
                error).
 
 @since 4.0
 */
- (void)client:(PubNub *)client didReceiveMessage:(PNResult *)message withStatus:(PNStatus *)status;

/**
 @brief  Notify listener about new presence events which arrived from one of remote data object's 
         presence live feed on which client subscribed at this moment.
 
 @param client Reference on \b PubNub client which triggered this callback method call.
 @param event  Reference on \b PNResult instance which store presence event information in
               \c data property.
 
 @since 4.0
 */
- (void)client:(PubNub *)client didReceivePresenceEvent:(PNResult *)event;


///------------------------------------------------
/// @name Status change handler.
///------------------------------------------------

/**
 @brief      Notify listener about subscription state changes.
 @discussion This callback can fire when client tried to subscribe on channels for which it doesn't
             have access rights or when network went down and client unexpectedly disconnected.
 
 @param client Reference on \b PubNub client which triggered this callback method call.
 @param status  Reference on \b PNStatus instance which store subscriber state information.
 
 @since 4.0
 */
- (void)client:(PubNub *)client didReceiveStatus:(PNStatus *)status;

#pragma mark -

@end
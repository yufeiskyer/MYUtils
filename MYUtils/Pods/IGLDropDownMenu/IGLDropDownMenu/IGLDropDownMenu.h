//
//  IGLDropDownMenu.h
//  IGLDropDownMenuDemo
//
//  Created by Galvin Li on 8/30/14.
//  Copyright (c) 2014 Galvin Li. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IGLDropDownItem.h"
@class IGLDropDownMenu;

typedef NS_ENUM(NSUInteger, IGLDropDownMenuRotate) {
    IGLDropDownMenuRotateNone,
    IGLDropDownMenuRotateLeft,
    IGLDropDownMenuRotateRight,
    IGLDropDownMenuRotateRandom
};

typedef NS_ENUM(NSUInteger, IGLDropDownMenuType) {
    IGLDropDownMenuTypeNormal,
    IGLDropDownMenuTypeStack,
    IGLDropDownMenuTypeSlidingInBoth,
    IGLDropDownMenuTypeSlidingInFromLeft,
    IGLDropDownMenuTypeSlidingInFromRight,
    IGLDropDownMenuTypeFlipVertical,
    IGLDropDownMenuTypeFlipFromLeft,
    IGLDropDownMenuTypeFlipFromRight
};

typedef NS_ENUM(NSUInteger, IGLDropDownMenuDirection) {
    IGLDropDownMenuDirectionDown,
    IGLDropDownMenuDirectionUp,
};

@protocol IGLDropDownMenuDelegate <NSObject>

@optional
- (void)dropDownMenu:(IGLDropDownMenu*)dropDownMenu selectedItemAtIndex:(NSInteger)index;
- (void)dropDownMenu:(IGLDropDownMenu *)dropDownMenu expandingChanged:(BOOL)isExpending;
- (void)dropDownMenu:(IGLDropDownMenu *)dropDownMenu expandingChangedWithAnimationCompledted:(BOOL)isExpending;

@end

@interface IGLDropDownMenu : UIControl

@property (nonatomic, strong) IGLDropDownItem *menuButton;
@property (nonatomic, copy) NSString* menuText;
@property (nonatomic, strong) id object;
@property (nonatomic, strong) UIImage *menuIconImage;
@property (nonatomic, copy) NSArray* dropDownItems;
@property (nonatomic, assign) CGSize itemSize;
@property (nonatomic, assign, readonly) NSInteger selectedIndex;

@property (nonatomic, assign) CGFloat paddingLeft;

@property (nonatomic, assign) CGFloat animationDuration;
@property (nonatomic, assign) UIViewAnimationOptions animationOption;
@property (nonatomic, assign) CGFloat itemAnimationDelay;
@property (nonatomic, assign) IGLDropDownMenuRotate rotate;
@property (nonatomic, assign) IGLDropDownMenuType type;
@property (nonatomic, assign) IGLDropDownMenuDirection direction;
@property (nonatomic, assign) CGFloat slidingInOffset;
@property (nonatomic, assign) CGFloat gutterY;
@property (nonatomic, assign) CGFloat alphaOnFold;
@property (nonatomic, assign, getter = isMenuButtonStatic) BOOL menuButtonStatic;
@property (nonatomic, assign, getter = isExpanding) BOOL expanding;
@property (nonatomic, assign, getter = shouldFlipWhenToggleView) BOOL flipWhenToggleView;
@property (nonatomic, assign, getter = shouldUseSpringAnimation) BOOL useSpringAnimation;

@property (nonatomic, weak) id<IGLDropDownMenuDelegate> delegate;

- (instancetype)initWithMenuButtonCustomView:(UIView*)customView;

- (void)reloadView;
- (void)resetParams;
- (void)selectItemAtIndex:(NSUInteger)index;
- (void)addSelectedItemChangeBlock:(void (^)(NSInteger selectedIndex))block;
- (void)toggleView;

@end

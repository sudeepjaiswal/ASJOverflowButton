//
// ASJOverflowButton.h
//
// Copyright (c) 2015-2016 Sudeep Jaiswal
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


#import "ASJOverflowMenu.h"
#import <UIKit/UIBarButtonItem.h>

@class ASJOverflowItem;

NS_ASSUME_NONNULL_BEGIN

typedef void (^ItemTapBlock)(ASJOverflowItem *item, NSInteger idx);
typedef void (^HideMenuBlock)();

@interface ASJOverflowButton : UIBarButtonItem

/**
 *  Called in response to menu item selection. Optional.
 */
@property (nullable, weak, nonatomic) id <ASJOverflowMenuDelegate> delegate;

/**
 *  The overflow menu's background color. Defaults to white.
 */
@property (nullable, strong, nonatomic) UIColor *menuBackgroundColor;

/**
 *  The overflow menu items' text color. Defaults to black.
 */
@property (nullable, strong, nonatomic) UIColor *itemTextColor;

/**
 *  The selected overflow menu item's background color when tapped. Defaults to RGB (217, 217, 217).
 */
@property (nullable, strong, nonatomic) UIColor *itemHighlightedColor;

/**
 *  The overflow menu items' font. Defaults to system font 17 pts.
 */
@property (nullable, strong, nonatomic) UIFont *itemFont;

/**
 *  It set YES, the separator between two menu items will be hidden. In that case, setting 'separatorInsets' will do nothing. Defaults to 'YES'.
 */
@property (assign, nonatomic) BOOL hidesSeparator;

/**
 *  If set YES, the shadow around the menu will not be drawn. Defaults to 'NO'.
 */
@property (assign, nonatomic) BOOL hidesShadow;

/**
 *  If set YES, the background will be dimmed while the menu is visible. Defaults to 'NO'.
 */
@property (assign, nonatomic) BOOL dimsBackground;

/**
 *  Sets the degree to which the background is dimmed when menu is shown. Will work only if 'dimsBackground' is set to 'YES'. Ranges from 0.0 to 1.0. Defaults to 0.6.
 */
@property (assign, nonatomic) CGFloat dimmingLevel;

/**
 *  Sets the height of individual overflow menu items. Defaults to 40 pts.
 */
@property (assign, nonatomic) CGFloat menuItemHeight;

/**
 *  Sets the ratio according to which the overflow menu width should be calculated. Acceptable values are from 0.0 to 1.0. For example, if your screen width is 320.0 pts and 'widthMultiplier' is set to 0.5, the menu width will be 0.5 * 320.0 = 160 pts. Defaults to 0.4.
 */
@property (assign, nonatomic) CGFloat widthMultiplier;

/**
 *  Sets the left and right insets of the separator between two menu items. Works only if 'hidesSeparator' is set to 'NO'. Defaults to (15.0f, 0.0f).
 */
@property (assign, nonatomic) SeparatorInsets separatorInsets;

/**
 *  The margins of the menu from the top, right and bottom edges. Defaults to 5 pts each.
 */
@property (assign, nonatomic) MenuMargins menuMargins;

/**
 *  Sets which way the menu should be shown; options including fading it in or zooming in from the top right corner. Defaults to 'MenuAnimationTypeZoomIn'.
 */
@property (assign, nonatomic) MenuAnimationType menuAnimationType;

/**
 *  A block that is called when any overflow menu item is tapped.
 */
@property (nullable, copy) ItemTapBlock itemTapBlock;

/**
 *  A block that is called when any overflow menu is removed from the screen.
 */
@property (nullable, copy) HideMenuBlock hideMenuBlock;

/**
 *  The designated initializer.
 *
 *  @param target A UIViewController to show the overflow menu on.
 *  @param image  The overflow buttn's image.
 *  @param items  An array of ASJOverflowItems to show on the menu.
 *
 *  @return An instance of ASJOverflowButton.
 */
- (instancetype)initWithImage:(UIImage *)image items:(NSArray<ASJOverflowItem *> *)items NS_DESIGNATED_INITIALIZER;

/**
 *  Don't allow user to use "init".
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 *  Don't allow user to use "initWithCoder:".
 */
- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (void)setItemTapBlock:(ItemTapBlock _Nullable)itemTapBlock;
- (void)setHideMenuBlock:(HideMenuBlock _Nullable)hideMenuBlock;

@end

@interface ASJOverflowItem : NSObject

/**
 *  The overflow item's name.
 */
@property (copy, nonatomic) NSString *name;

/**
 *  The overflow item's image. Optional.
 */
@property (nullable, strong, nonatomic) UIImage *image;

/**
 *  The overflow item's background color. Optional.
 */
@property (nullable, strong, nonatomic) UIColor *backgroundColor;

/**
 *  A convenience constructor to create ASJOverflowItems.
 *
 *  @param name  The overflow item's name.
 *
 *  @return An instance of ASJOverflowItem.
 */
+ (ASJOverflowItem *)itemWithName:(NSString *)name;

/**
 *  A convenience constructor to create ASJOverflowItems.
 *
 *  @param name  The overflow item's name.
 *  @param image The overflow item's image. Optional.
 *  @param image The overflow item's background color. Optional.
 *
 *  @return An instance of ASJOverflowItem.
 */
+ (ASJOverflowItem *)itemWithName:(NSString *)name image:(nullable UIImage *)image backgroundColor:(nullable UIColor *)backgroundColor;

@end

NS_ASSUME_NONNULL_END

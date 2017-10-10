//
//  ViewController.h
//  CardGame
//
//  Created by Qiao Jian on 17/9/11.
//  Copyright © 2017年 Qiao Jian. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Deck.h"

@interface ViewController : UIViewController
{
// instance variables
@private
@protected
@package
@public
}
// public methods
-(Deck*)createDeck; //usually, not must, abstract method need to be public

@end


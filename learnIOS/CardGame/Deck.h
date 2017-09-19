//
//  Deck.h
//  CardGame
//
//  Created by Qiao Jian on 17/9/12.
//  Copyright © 2017年 Qiao Jian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Card.h"

@interface Deck : NSObject

-(void) addCard:(Card*)card atTop:(BOOL) atTop;
-(void) addCard:(Card *)card;
-(Card*) drawRandomCard;

@end

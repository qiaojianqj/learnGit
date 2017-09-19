//
//  CardMatchingGame.h
//  CardGame
//
//  Created by Qiao Jian on 17/9/18.
//  Copyright © 2017年 Qiao Jian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Deck.h"

@interface CardMatchingGame : NSObject
//designate initializer
-(instancetype) initWithCardCount:(NSUInteger)count usingDeck:(Deck*) deck;
-(void) chooseCardAtIndex:(NSUInteger) index;
-(Card*) cardAtIndex:(NSUInteger) index;
@property (nonatomic, readonly) int score;
@end

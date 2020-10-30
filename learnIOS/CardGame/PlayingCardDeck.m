//
//  PlayingCardDeck.m
//  CardGame
//
//  Created by Qiao Jian on 17/9/13.
//  Copyright © 2017年 Qiao Jian. All rights reserved.
//

#import "PlayingCardDeck.h"
#import "PlayingCard.h"

@implementation PlayingCardDeck

-(instancetype) init {
    self = [super init];
    if (self) {
        for (NSString* suit in [PlayingCard validSuits]) {
            for (NSUInteger rank = 1; rank <= [PlayingCard maxRank]; rank++) {
                PlayingCard* card = [[PlayingCard alloc] init];
                card.suit = suit;
                card.rank = rank;
                NSLog(@"rank : %lu", rank);
                NSLog(@"card rank: %lu", card.rank);
                [self addCard:card];
            }
        }
    }
    return self;
}

@end

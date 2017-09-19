//
//  Deck.m
//  CardGame
//
//  Created by Qiao Jian on 17/9/12.
//  Copyright © 2017年 Qiao Jian. All rights reserved.
//

#import "Deck.h"

@interface Deck()
@property (nonatomic, strong) NSMutableArray *cards;
@end

@implementation Deck

-(NSMutableArray *)cards {
    if (!_cards) {
        _cards = [[NSMutableArray alloc] init];
    }
    return _cards;
}

- (void)addCard:(Card *)card atTop:(BOOL)atTop {
    if (atTop) {
        [self.cards insertObject:card atIndex:0];
    } else {
        [self.cards addObject:card];
    }
}

- (void)addCard:(Card *)card {
    [self addCard:card atTop:false];
}

- (Card *)drawRandomCard {
    
    int index = 0;
    Card * randomCard = nil;
    if ([self.cards count]) {
        index = arc4random() % [self.cards count];
        randomCard = [self.cards objectAtIndex:index];
        [self.cards removeObjectAtIndex:index];
    }
    NSLog(@"random card: %@", randomCard.contents);
    return randomCard;
}

@end

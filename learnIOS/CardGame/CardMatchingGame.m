//
//  CardMatchingGame.m
//  CardGame
//
//  Created by Qiao Jian on 17/9/18.
//  Copyright © 2017年 Qiao Jian. All rights reserved.
//

//caution:
//[Local variables] that are basic C data types have no default initial value, so you must set them to some value before using them.

#import "CardMatchingGame.h"

@interface CardMatchingGame ()
@property (nonatomic, readwrite) int score;
@property (nonatomic, strong) NSMutableArray* cards;
@end

@implementation CardMatchingGame
-(NSMutableArray*) cards {
    if (!_cards) {
        _cards = [[NSMutableArray alloc] init];
    }
    return _cards;
}

-(instancetype) initWithCardCount:(NSUInteger)count usingDeck:(Deck *)deck {
    self = [super init];//super's designated initializer
    if (self) {
        for (int i = 0; i < count; i++) {
            Card* card = [deck drawRandomCard];
            if (card) {
                [self.cards addObject:card];
            } else {
                self = nil;
                break;
            }
        }
    }
    return self;
}

static const int MISMATCH_PENALTY = 1;
static const int MATCH_BONUS = 2;
static const int COST_TO_CHOSE = 1;

-(void) chooseCardAtIndex:(NSUInteger)index {
    //Card* card = self.cards[index];
    Card* card = [self cardAtIndex:index];
    if (!card.isMatched) {
        if (card.isChosen) {
            card.chosen = NO;
        } else {
            //match against other chosen cards
            for (Card* otherCard in self.cards) {
                if (otherCard.isChosen && !otherCard.isMatched) {
                    int matchScore = 0; //Here, int variable if not initialized, the default value will not 0
                    matchScore = [card match:@[otherCard]];
                    if (matchScore) {
                        self.score += matchScore * MATCH_BONUS;
                        card.matched = YES;
                        otherCard.matched = YES;
                    } else {
                        self.score -= MISMATCH_PENALTY;
                        otherCard.chosen = NO;
                    }
                    break;
                }
            }
            self.score -= COST_TO_CHOSE;
            card.chosen = YES;
        }
    }
}

-(Card*) cardAtIndex:(NSUInteger)index {
    return (index < [self.cards count]) ? self.cards[index] : nil;
}
@end

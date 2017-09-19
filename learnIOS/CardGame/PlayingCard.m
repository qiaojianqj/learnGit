//
//  PlayingCard.m
//  CardGame
//
//  Created by Qiao Jian on 17/9/12.
//  Copyright © 2017年 Qiao Jian. All rights reserved.
//

#import "PlayingCard.h"


@implementation PlayingCard

@synthesize suit = _suit; //this is needed if both setter and getter is written by hand


-(int) match:(NSArray *)otherCards {
    int score = 0; //Here, int variable if not initialized, the default value will not 0
    if ([otherCards count] == 1) {
        PlayingCard* otherCard = [otherCards firstObject];
        if (self.rank == otherCard.rank) {
            score = 4;
        } else if ([self.suit isEqualToString: otherCard.suit]) {
            score = 2;
        }
    }
    return score;
}

+(NSArray*) rankStrings {
    return @[@"?", @"A", @"2", @"3", @"4", @"5", @"6", @"7", @"8", @"9", @"10", @"J", @"Q", @"K"];
}

+(NSUInteger) maxRank {
    return [[self rankStrings] count]-1;
}

-(void) setRank:(NSUInteger)rank {
    if (rank <= [PlayingCard maxRank]) {
        _rank = rank;
    }
}

-(NSString *)contents {
    NSArray *rankStrings = [PlayingCard rankStrings];
    
    return [rankStrings[self.rank] stringByAppendingString:self.suit];
}

+(NSArray*) validSuits {
    return @[@"♠️", @"♣️", @"♥️", @"♦️"];
}

-(void) setSuit:(NSString *)suit {
    if ([[PlayingCard validSuits] containsObject: suit]) {
        _suit = suit;
    }
}

-(NSString*) suit {
    return _suit ? _suit : @"?";
}



@end

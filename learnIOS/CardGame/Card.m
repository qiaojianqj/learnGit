//
//  Card.m
//  CardGame
//
//  Created by Qiao Jian on 17/9/12.
//  Copyright © 2017年 Qiao Jian. All rights reserved.
//

#import "Card.h"

@implementation Card

-(int) match:(NSArray *)otherCards
{
    int score = 0;
    for (Card *card in otherCards) {
        if ([card.contents isEqualToString:self.contents]) {
            score ++;
        }
    }
    return score;
}

@end

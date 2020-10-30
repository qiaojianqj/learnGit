//
//  PlayingCard.h
//  CardGame
//
//  Created by Qiao Jian on 17/9/12.
//  Copyright © 2017年 Qiao Jian. All rights reserved.
//

#import "Card.h"

@interface PlayingCard : Card

@property (nonatomic, strong) NSString* suit;
@property (nonatomic) NSUInteger rank;

+(NSArray*) validSuits;
+(NSUInteger) maxRank;

@end

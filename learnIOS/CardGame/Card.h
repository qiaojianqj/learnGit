//
//  Card.h
//  CardGame
//
//  Created by Qiao Jian on 17/9/12.
//  Copyright © 2017年 Qiao Jian. All rights reserved.
//

#ifndef Card_h
#define Card_h

#import <Foundation/Foundation.h>

@interface Card : NSObject
@property (nonatomic, strong) NSString* contents;
@property (nonatomic, getter=isChosen) BOOL chosen;
@property (nonatomic, getter=isMatched) BOOL matched;

-(int) match:(NSArray *)otherCards;

@end
#endif /* Card_h */

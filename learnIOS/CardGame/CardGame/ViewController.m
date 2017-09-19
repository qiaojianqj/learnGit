//
//  ViewController.m
//  CardGame
//
//  Created by Qiao Jian on 17/9/11.
//  Copyright © 2017年 Qiao Jian. All rights reserved.
//

//Problems:
//1. property deck must be strong,
//   otherwise touchinside button will show nothing.


#import "ViewController.h"
#import "PlayingCardDeck.h"
#import "CardMatchingGame.h"

@interface ViewController ()
/*
@property (weak, nonatomic) IBOutlet UILabel *flipLabel;
@property (nonatomic) int flipCount;
@property (nonatomic, strong) Deck* deck;
*/
@property (nonatomic, strong) CardMatchingGame* game;
@property (strong, nonatomic) IBOutletCollection(UIButton) NSArray *cardButtons;
@property (weak, nonatomic) IBOutlet UILabel *scoreLable;
@end


@implementation ViewController

-(CardMatchingGame*) game {
    if (!_game) {
        _game = [[CardMatchingGame alloc] initWithCardCount:[self.cardButtons count] usingDeck:[self createDeck]];
    }
    return _game;
}

-(Deck*) createDeck {
    return [[PlayingCardDeck alloc] init];
}

/*
-(Deck *) deck {
    if (!_deck) {
        _deck = [self createDeck];
    }
    return _deck;
}

- (void)setFlipCount:(int)flipCount {
    _flipCount = flipCount;
    self.flipLabel.text = [NSString stringWithFormat:@"flip: %d", self.flipCount];
}
*/

- (IBAction)touchCardButton:(UIButton *)sender {
    /*
    if ([sender.currentTitle length]) {
        [sender setBackgroundImage:[UIImage imageNamed:@"cardback"]
                      forState:UIControlStateNormal];
        [sender setTitle:@"" forState:UIControlStateNormal];
    } else {
        Card* card = [self.deck drawRandomCard];
        if (card) {
            [sender setBackgroundImage:[UIImage imageNamed:@"cardfront"]
                              forState:UIControlStateNormal];
            [sender setTitle:card.contents forState:UIControlStateNormal];
        }
    }
    */
    NSUInteger chosenCardIndex = [self.cardButtons indexOfObject:sender];
    [self.game chooseCardAtIndex:chosenCardIndex];
    [self updateUI];
    /*
    self.flipCount++;
     */
}

-(void) updateUI {
    for (UIButton* cardButton in self.cardButtons) {
        NSUInteger cardButtonIndex = [self.cardButtons indexOfObject:cardButton];
        Card* card = [self.game cardAtIndex:cardButtonIndex];
        [cardButton setTitle:[self titleForCard:card] forState:UIControlStateNormal];
        [cardButton setBackgroundImage:[self backgroundImageForCard:card] forState:UIControlStateNormal];
        cardButton.enabled = !card.isMatched;
        self.scoreLable.text = [NSString stringWithFormat:@"Score: %d", self.game.score];
    }
}

-(NSString*) titleForCard: (Card*) card {
    return card.isChosen ? card.contents : @"";
}

-(UIImage*) backgroundImageForCard: (Card*) card {
    return [UIImage imageNamed: card.isChosen ? @"cardfront" : @"cardback" ];
}
@end

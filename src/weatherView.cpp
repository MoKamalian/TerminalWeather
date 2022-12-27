/*
 * author: amir kamalian
 * date:   dec 26, 2022
 *
 */


#include "../inc/weatherView.h"

/* displays sun ASCII art, example for sunny weather */
void WeatherView::displaySun() {
    const char* sunArt = R"(
        .
      \ | /
    '-.;;;.-'
   -==;;;;;==-
    .-';;;'-.
      / | \
        '
    )";
    std::cout << sunArt << std::endl;
};

/* display rain ASCII art, example for when weather is raining */
void WeatherView::displayRain() {
    const char* rainArt = R"(
      __   _
    _(  )_( )_
   (_   _    _)
  / /(_) (__)
 / / / / / /
/ / / / / /
    )";
    std::cout << rainArt << std::endl;
};

/* display art for when weather is cloudy; this is a different view
 * from rain */
void WeatherView::displayCloudy() {
    const char* cloudArt = R"(
                _
              (`  ).                   _
             (     ).              .:(`  )`.
            _(       '`.          :(   .    )
        .=(`(      .   )     .--  `.  (    ) )
       ((    (..__.:'-'   .+(   )   ` _`  ) )
       `(       ) )       (   .  )     (   )  ._
         ` __.:'   )     (   (   ))     `-'.-(`  )
      ( )       --'       `- __.'         :(      ))
     (_.'          .')                    `(    )  ))
                  (_  )                     ` __.:'
    )";
    std::cout << cloudArt << std::endl;
};

/* displays thunder ASCII art, example for when the weather is thunder/lightning */
void WeatherView::displayThunder() {
    const char* thunderArt = R"(
                      .-~*~--,.   .-.
          .-~-. ./OOOOOOOOO\.'OOO`9~~-.
        .`OOOOOO.OOM.OLSONOOOOO@@OOOOOO\
       /OOOO@@@OO@@@OO@@@OOO@@@@@@@@OOOO`.
       |OO@@@WWWW@@@@OOWWW@WWWW@@@@@@@OOOO).
     .-'OO@@@@WW@@@W@WWWWWWWWOOWW@@@@@OOOOOO}
    /OOO@@O@@@@W@@@@@OOWWWWWOOWOO@@@OOO@@@OO|
   lOOO@@@OO@@@WWWWWWW\OWWWO\WWWOOOOOO@@@O.'
    \OOO@@@OOO@@@@@@OOW\     \WWWW@@@@@@@O'.
     `,OO@@@OOOOOOOOOOWW\     \WWWW@@@@@@OOO)
      \,O@@@@@OOOOOOWWWWW\     \WW@@@@@OOOO.'
        `~c~8~@@@@WWW@@W\       \WOO|\UO-~'
             (OWWWWWW@/\W\    ___\WO)
               `~-~''     \   \WW=*'
                         __\   \
                         \      \
                          \    __\
                           \  \
                            \ \
                             \ \
                              \\
                               \\
                                \
                                 \
    )";
    std::cout << thunderArt << std::endl;
};

/* display snowfall ASCII art, this is for light to medium snow fall weather */
void WeatherView::displaySnowfall() {
    const char* snowfallArt = R"(
            ...        *                        *       *
      ...   *         * ..   ...                        *
 *      ...        *           *            *
          ...               ...                          *
            ..                            *
    *        ..        *                       *
           __##____              *                      *
  *    *  /  ##  ****                   *
         /        ****               *         *  X   *
   *    /        ******     *                    XXX      *
       /___________*****          *             XXXXX
        |            ***               *       XXXXXXX   X
    *   | ___        |                    *   XXXXXXXX  XXX
  *     | | |   ___  | *       *             XXXXXXXXXXXXXXX
        | |_|   | |  ****             *           X   XXXXXXX
    *********** | | *******      *                X      X
************************************************************
    )";
    std::cout << snowfallArt << std::endl;
};

/* display for snow storm or blizzard ASCII art */
void WeatherView::displaySnowStorm() {
    const char* snowstormArt = R"(
          .-~~~-.
  .- ~ ~-(       )_ _
 /                    ~ -.
|                          ',
 \                         .'
   ~- ._ ,. ,.,.,., ,.. -~
    * .  .  *    .  *   *  .
   .  *   .  * *  .    .  *
     *  .  *  ..  .  *   * . *
   * *  . *  * .   *  .  . *
    )";
    std::cout << snowstormArt << std::endl;
};


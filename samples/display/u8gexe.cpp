#include "Arduino.h"
#include "U8glib.h"

#include "assets/bitmaps.h"

/*
 * U8glib references at: https://github.com/olikraus/u8glib/wiki/userreference
 *
 * SCREEN AXIS:
 *
 * (0, 0)   ·-------------------------------> (128, 0)
 *          |
 *          |
 * (0, 64)  v                               · (128, 64)
 *
 */
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);  /* I2C / TWI */

const u8g_fntpgm_uint8_t *FONT = u8g_font_04b_03br;  /* Put desired */

const uint16_t DELAY_DEMO_IN_MS = 2000;
const uint16_t DELAY_ANIMATION_IN_MS = 300;
const uint16_t DELAY_REFRESH_IN_MS = 50;

const uint8_t SCREEN_WIDTH = 127;
const uint8_t SCREEN_WIDTH_2 = 63;
const uint8_t SCREEN_WIDTH_4 = 31;
const uint8_t SCREEN_WIDTH_8 = 15;
const uint8_t SCREEN_HEIGHT = 63;
const uint8_t SCREEN_HEIGHT_2 = 31;
const uint8_t SCREEN_HEIGHT_4 = 15;
const uint8_t SCREEN_HEIGHT_8 = 7;

const uint8_t MAX_PIXELS = 89;

#define WHITE_COLOR 255

enum pixel_mode
{
    PIXEL_CLEAR = 0,    /* OFF */
    PIXEL_SET,          /* ON */
};

enum intensity
{
    INTENSITY_NONE = 0,
    INTENSITY_LOW,
    INTENSITY_MEDIUM,
    INTENSITY_MAX,
};

void clear_screen()
{
    u8g.firstPage();
    do {
    } while( u8g.nextPage() );
    delay(DELAY_REFRESH_IN_MS);
}

void print_hello_world()
{
    /* Marks the beginning of the picture loop */
    u8g.firstPage();
    do
    {
        u8g.drawStr( SCREEN_WIDTH_4, SCREEN_HEIGHT_2, "Hello World!");
    } while( u8g.nextPage() );
}

void print_pixels()
{
    uint8_t x_pos = 0;
    uint8_t y_pos = 0;
    uint8_t i = 0;

    u8g.firstPage();
    do
    {
        for(i = 0; i <= MAX_PIXELS; i++)
        {
            x_pos = rand() % SCREEN_WIDTH;
            y_pos = rand() % SCREEN_HEIGHT;
            u8g.drawPixel(x_pos, y_pos);
            u8g.drawStr( SCREEN_WIDTH_2 - SCREEN_WIDTH_8, SCREEN_HEIGHT_2, "S T A R S");
        }
    } while( u8g.nextPage() );
}

void print_geobros()
{
    const uint8_t TOP = SCREEN_HEIGHT_2;
    const uint8_t BOTTOM = SCREEN_HEIGHT_2 + SCREEN_WIDTH_8;
    const uint8_t FIRST_POS_X = SCREEN_WIDTH_4;
    const uint8_t SECOND_POS_X = SCREEN_WIDTH_2 + SCREEN_WIDTH_8/2;
    const uint8_t THIRD_POS_X = SCREEN_WIDTH_4 + SCREEN_WIDTH_2;

    u8g.firstPage();
    do
    {
        u8g.drawStr(SCREEN_WIDTH_2 - SCREEN_WIDTH_8, TOP - SCREEN_WIDTH_8, "GEOBROS!");
        u8g.drawFrame(FIRST_POS_X, TOP,
                    SCREEN_WIDTH_8, SCREEN_WIDTH_8);
        u8g.drawCircle(SECOND_POS_X, TOP + SCREEN_WIDTH_8 / 2,
                    SCREEN_WIDTH_8/2, U8G_DRAW_ALL);
        /* Draw empty triangle */
        u8g.drawLine(THIRD_POS_X, BOTTOM, THIRD_POS_X + SCREEN_WIDTH_8/2, TOP);
        u8g.drawLine(THIRD_POS_X + SCREEN_WIDTH_8/2, TOP, THIRD_POS_X + SCREEN_WIDTH_8, BOTTOM);
        u8g.drawLine(THIRD_POS_X + SCREEN_WIDTH_8, BOTTOM, THIRD_POS_X, BOTTOM);

    } while( u8g.nextPage() );
}

void print_bmp()
{
    u8g.firstPage();
    do
    {
        u8g.drawBitmapP(0, 0, 1, 8, rook_bitmap);
        u8g.drawBitmapP(8, 8, SPRITE[0], SPRITE[1], SPRITE + 2);
    } while( u8g.nextPage() );
}

void print_bmp_invert()
{
    u8g.setColorIndex(PIXEL_CLEAR);
    print_bmp();
    u8g.setColorIndex(PIXEL_SET);
}

void print_animation()
{

    delay(DELAY_ANIMATION_IN_MS);
}

void draw(void)
{
    print_hello_world();
    delay(DELAY_DEMO_IN_MS);
    clear_screen();

    print_pixels();
    delay(DELAY_DEMO_IN_MS);
    clear_screen();

    print_geobros();
    delay(DELAY_DEMO_IN_MS);
    clear_screen();

    print_bmp();
    delay(DELAY_DEMO_IN_MS);
    clear_screen();

    //print_bmp_invert();
    //delay(DELAY_DEMO_IN_MS);
    //clear_screen();
    // invert_region();
    // delay(DELAY_DEMO_IN_MS);
    print_animation();
    clear_screen();
}

void setup(void)
{
    /* Set color mode */
    if ( u8g.getMode() == U8G_MODE_R3G3B2 )
    {
        u8g.setColorIndex(WHITE_COLOR);
    }
    else if ( u8g.getMode() == U8G_MODE_GRAY2BIT )
    {
        u8g.setColorIndex(INTENSITY_MAX);
    }
    else if ( u8g.getMode() == U8G_MODE_BW )
    {
        /* Set pixel value 1 --> turn on; value 0 --> turn off */
        u8g.setColorIndex(PIXEL_SET);
    }
    else if ( u8g.getMode() == U8G_MODE_HICOLOR )
    {
        /* RGB all max = White */
        u8g.setHiColorByRGB(255, 255, 255);
    }

    /* Set font */
    u8g.setFont(FONT);
}

void loop(void)
{
    draw();
    delay(DELAY_DEMO_IN_MS);
}

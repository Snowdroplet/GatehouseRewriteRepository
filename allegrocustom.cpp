#include "allegrocustom.h"

ALLEGRO_COLOR PEN_INK;

void AllegroCustomColours()
{
    PEN_INK = al_map_rgb(77,79,112);

}

void c_al_draw_centered_bitmap(ALLEGRO_BITMAP *bitmap, float dx, float dy, int flags)
{
    al_draw_bitmap(bitmap,
                   dx-al_get_bitmap_width(bitmap)/2, dy-al_get_bitmap_height(bitmap)/2,
                   flags);
}

void c_al_draw_rotated_centered_bitmap(ALLEGRO_BITMAP *bitmap, float cx, float cy, float dx, float dy, float angle, int flags)
{
    al_draw_rotated_bitmap(bitmap,
                           cx, cy,
                           dx-al_get_bitmap_width(bitmap)/2, dy-al_get_bitmap_height(bitmap)/2,
                           angle, flags);
}

int s_al_get_text_width(const ALLEGRO_FONT *f, std::string str)
{
    const char *c = str.c_str();
    return al_get_text_width(f, c);
}

void s_al_draw_text(const ALLEGRO_FONT *font, ALLEGRO_COLOR color, float x, float y, int flags, std::string text)
{
    const char *c = text.c_str();
    al_draw_text(font, color, x, y, flags, c);
}

void al_draw_centered_text(const ALLEGRO_FONT *font, ALLEGRO_COLOR color, float x, float y, int flags, char const* text)
{
    // Note that this function only centers on the y dimension, neglecting the x, because too convoluted.
    al_draw_text(font, color, x, y-al_get_font_line_height(font)/2, flags, text);
}

void s_al_draw_centered_text(const ALLEGRO_FONT *font, ALLEGRO_COLOR color, float x, float y, int flags, std::string text)
{
    // Note that this function only centers on the y dimension, neglecting the x, because too convoluted.
    const char *c = text.c_str();
    al_draw_text(font, color, x, y-al_get_font_line_height(font)/2, flags, c);
}

int s_al_show_native_message_box(ALLEGRO_DISPLAY *display,
                                 std::string title, std::string heading, std::string text,
                                 char const *buttons, int flags)
{
    const char *ctitle = title.c_str();
    const char *cheading = heading.c_str();
    const char *ctext = text.c_str();

    return al_show_native_message_box(display, ctitle, cheading, ctext, buttons, flags);
}

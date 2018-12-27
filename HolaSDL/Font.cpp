#/*include "Font.h"

Font::Font()
{

}

Font::Font(string filename, int size)
{
	load(filename, size);

}

Font::~Font()
{
	clean();

}

void Font::load(string filename, int size)
{
	font = TTF_OpenFont(filename.c_str(), size);
}

void Font::clean()
{
	if (font != nullptr)
		TTF_CloseFont(font);
	font = nullptr;
}

SDL_Surface * Font::generateSurface(string text, SDL_Color color) const
{
	return TTF_RenderText_Solid(font, text.c_str(), color);
}*/

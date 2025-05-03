#include "Lable.h"

void Lable::Compute_Centering_Text_Coordinate()
{
	settextstyle(Lablestyle.LableHeight, Lablestyle.LableWidth, Lablestyle.LableTypeface.c_str());
	TextWidth = textwidth(Text.c_str());
	TextHeight = textheight(Text.c_str());
	Centering_Text_X = Lableposition.x + (Lableposition.RectWidth - TextWidth) / 2;
	Centering_Text_Y = Lableposition.y + (Lableposition.RectHeight - TextHeight) / 2;
}

void Lable::DrawLable()
{
	settextcolor(Lablestyle.color);
	settextstyle(Lablestyle.LableHeight, Lablestyle.LableWidth, Lablestyle.LableTypeface.c_str());
	outtextxy(Centering_Text_X, Centering_Text_Y, Text.c_str());
}
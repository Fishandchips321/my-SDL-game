#include "itemSelectWidget.h"


itemSelectWidget::itemSelectWidget(int x, int y)
{
	WRect.x = x;
	WRect.y = y;
	WRect.w = 30;
	WRect.h = 30;
	IRect.x = x + 5;
	IRect.y = y + 5;
	IRect.w = WRect.w - 10;
	IRect.h = WRect.h - 10;
	selected = false;
}

void itemSelectWidget::draw()
{
	if (selected == false)
		render::drawSquare(WRect, 0x00, 0xff, 0x00, 0xaa);

	if (selected == true)
		render::drawSquare(WRect, 0xff, 0x00, 0x00, 0xaa);

	if (item.SItem != nullptr && item.SItem->iTexture != nullptr)
		render::drawTexture(item.SItem->iTexture, &IRect);
}

itemSelectWidget::~itemSelectWidget()
{
}

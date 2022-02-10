сделать редактор цветов не монолитной вкладкой, а страницей описаной в текстовом формате.

page{
  name="page with color selector"
  items={
    rect{name="rect"}
    rect_with_scrollbar{name="r"}
    rect_with_scrollbar{name="g"}
    rect_with_scrollbar{name="b"}
    rect_with_scrollbar{name="a"}
    script{
      code={
        page.rect.
      }
    }
  }
}
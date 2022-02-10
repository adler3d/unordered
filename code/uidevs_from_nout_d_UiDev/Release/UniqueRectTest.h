book.pages[2].build{IBookPage}()
book.pages[2].build{TBookPage20140814}()
book.pages[2].get().Caption=self.editor.buffer
book.pages[2].get{TBookPage20140814}().root.points.clear()
book.pages[2].get{TBookPage20140814}().root.points.emplace_back()
book.pages[2].get{TBookPage20140814}().root.points.back().rect.w=256
book.pages[2].get{TBookPage20140814}().root.points.back().rect.h=400
book.pages[2].get{TBookPage20140814}().root.points.back().points.emplace_back()
book.pages[2].get{TBookPage20140814}().root.points.back().rect.draw_points=1
book.pages[2].get{TBookPage20140814}().root.points.emplace_back()
book.pages[2].get{TBookPage20140814}().root.points.back().rect.pos.x=100
book.pages[2].get{TBookPage20140814}().root.points.back().rect.w=256
book.pages[2].get{TBookPage20140814}().root.points.back().rect.h=400
book.pages[2].get{TBookPage20140814}().root.points.back().points.emplace_back()
book.pages[2].get{TBookPage20140814}().root.points.back().points.back().rect.pos.y=50
book.pages[2].get{TBookPage20140814}().root.points.back().points.emplace_back()
book.pages[2].get{TBookPage20140814}().root.points.back().rect.draw_points=1
book.pages[2].get{TBookPage20140814}().root.points.emplace_back()
book.pages[2].get{TBookPage20140814}().root.points.back().rect.pos.y=100
book.pages[2].get{TBookPage20140814}().root.points.back().rect.w=150
book.pages[2].get{TBookPage20140814}().root.points.back().rect.h=500
book.pages[2].get{TBookPage20140814}().root.points.back().rect.draw_points=1


self.buff_arr.clear()
self.buff_arr.emplace_back()
prevbook.pages[0].get{TBookPageWithMultyBook}().books[0].book.pages[2].get().Caption=self.buff_arr[0]


Написал скрипт копирующий вкладку из одной книги в другую, но он не работает, т.к внутри вкладки умный следящий указатель на внешний объект.
Ладно скопирую руками.

prevbook.pages[1].get{TBookPageWithMultyBook}().books[1].book.pages[0]=root.Scene.Items[1].get{TRenderNode}().Items[1].get{TDay20140605BookV00}().book.pages[0]

self.buff_arr.clear()
self.buff_arr.emplace_back()
self.buff_arr.emplace_back()
self.buff_arr[0]=prevbook.pages[1].get{TBookPageWithMultyBook}().books[1].


.?

root.Scene.Items[1].get{TRenderNode}().Items[1].get{TDay20140605BookV00}().book.pages[0]?


[2014.08.11]
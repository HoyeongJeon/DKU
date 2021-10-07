select max(bookid) from Book;

call InsertBook(16, '책의 기록', 'DKU', 50000);

select * from Book order by bookid desc;

select * from Book_log;
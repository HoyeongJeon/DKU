use madang;

create view vw_book
as
select *
from Book
where bookname like '%축구%';

select * from vw_Book;

drop view vw_Book;
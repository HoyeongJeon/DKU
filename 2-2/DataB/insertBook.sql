use madang;
delimiter //

create procedure BookInsertOrUpdate(
	in mybookID integer,
    in myBookName varchar(40),
    in myPublisher varchar(40),
    in myPrice integer
)
begin 
	declare mycount integer; -- 책이 있는지 확인할 것..
    select count(*) into mycount from Book
		where bookname like myBookName;
	
    if mycount != 0 then
		set sql_safe_updates = 0;-- 0 이면 업데이트 가능 
        update Book set price = myPrice
			where bookname like myBookName;
	else 
		insert into Book(bookid, bookname, publisher, price)
			values(myBookID, myBookName, myPublisher, myPrice);
	end if;
end;
//

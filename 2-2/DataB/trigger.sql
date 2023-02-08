delimiter //
create trigger AfterInsertBook
after insert on Book for each row
begin 
	insert into Book_log
    values(new.bookid, new.bookname, new.publisher, new.price);
end;
//
delimiter ;
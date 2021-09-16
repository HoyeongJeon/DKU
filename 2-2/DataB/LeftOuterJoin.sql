use madang;


select name, address
from Customer as c
where exists (select * from Orders as o where c.custid = o.custid);
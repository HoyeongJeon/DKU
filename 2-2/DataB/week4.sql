use madang;

alter table NewBook add isbn varchar(13); -- isbn 테이블 추가

alter table NewBook modify isbn integer; -- isbn 테이블의 타입 수정

alter table NewBook drop column isbn; -- isbn 컬럼을 제거

alter table NewBook add bookid integer; -- bookid라는 컬럼을 NewBook에 넣음

alter table NewBook modify bookid integer not null; -- bookid null 못 넣게 바꿈

desc NewBook; -- 허용이 되는 부분과 안되는 부분을 볼 수 있게 해주는 명령어
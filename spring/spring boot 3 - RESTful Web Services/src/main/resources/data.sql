insert into users(id, join_date, name, password, ssn)
values (90001, now(), 'Users1', 'test111', '701010-1111111');
insert into users(id, join_date, name, password, ssn)
values (90002, now(), 'Users2', 'test211', '801010-1111111');
insert into users(id, join_date, name, password, ssn)
values (90003, now(), 'Users3', 'test311', '901010-1111111');

insert into post(description, user_id) values ('my_first_date', 90001);
insert into post(description, user_id) values ('my_second_date', 90001);
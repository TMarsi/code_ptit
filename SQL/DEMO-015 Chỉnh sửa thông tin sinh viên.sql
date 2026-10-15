alter table Students
modify column student_id int not null AUTO_INCREMENT,
modify column birth_date date,
modify column email varchar(255) not null,
modify column phone varchar(50) not null,
add column created_at datetime default current_timestamp,
add primary key (student_id);
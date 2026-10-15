alter table Products
modify column id int not null AUTO_INCREMENT, 
modify column price decimal(10,2) not null,
ADD CONSTRAINT chk_price_non_negative CHECK (price >= 0),
modify column status enum('ACTIVE','INACTIVE','DISCONTINUED') not null default 'ACTIVE',
modify column created_at datetime default current_timestamp,
modify column category varchar(100) not null,
drop column temp_note,
add primary key (id);
alter table Inventory 
modify column item_id int not null ,
modify column quantity int not null default 0,
modify column unit_price DECIMAL(10,2) not null default 0,
modify column status enum('IN_STOCK','OUT_OF_STOCK','STOPPED') not null default 'IN_STOCK',
modify column last_updated DATETIME default current_timestamp,
add column note varchar(255),
drop column temp_col,
add primary key (item_id);
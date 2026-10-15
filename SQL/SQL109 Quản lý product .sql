create table products(
  product_id int primary key auto_increment,
  product_name  VARCHAR(255) not null,
  category VARCHAR(100),
  price DECIMAL(10, 2),
  stock_quantity int,
  created_at timestamp default current_timestamp
);
create table REVIEW(
  ReviewID int primary key,
  CustID int not null,
  ProductID int not null,
  Rating TINYINT not null check(Rating between 1 and 5),
  Comment varchar(500),
  CreatedAt TIMESTAMP not null default current_timestamp,
  unique (CustID,ProductID),
  foreign key (CustID) references CUSTOMER(CustID),
  foreign key (ProductID) references PRODUCT(ProductID)
);
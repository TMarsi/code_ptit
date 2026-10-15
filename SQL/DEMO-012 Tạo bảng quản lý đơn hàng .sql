create table SALEORDER  (
  OrderID int primary key ,
  CustID int not null,
  TotalAmount DECIMAL(12,2) not null check(TotalAmount > 0),
  Status ENUM('NEW','PAID','CANCELLED') not null,
  foreign key (CustID) references CUSTOMER(CustID)
);
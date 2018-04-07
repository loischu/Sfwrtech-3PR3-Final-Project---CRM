CREATE SCHEMA dbo;

USE dbo;

CREATE TABLE Company
(
	Company_ID int PRIMARY KEY AUTO_INCREMENT,
    Company_Name text,
    Address text,
    Sector text
);

CREATE TABLE Client
(
	Client_ID int PRIMARY KEY AUTO_INCREMENT,
    Company_ID int,
    Title text,
    Client_Name text,    
    Email_Address text,
    Phone_Number text,
    Physical_Address text,
    Notes text,
    FOREIGN KEY (Company_ID) REFERENCES Company(Company_ID)
);

CREATE TABLE Customer_Service_Representative
(
	Rep_ID int PRIMARY KEY AUTO_INCREMENT,
    Name text
);

CREATE TABLE `Case`
(
	Case_ID int PRIMARY KEY AUTO_INCREMENT,
    Client_ID int,
    Rep_ID int,
    Details text,
    Type text,    FOREIGN KEY (Client_ID) REFERENCES Client(Client_ID),
    FOREIGN KEY (Rep_ID) REFERENCES Customer_Service_Representative(Rep_ID)
);

INSERT INTO Company (Company_Name, Address, Sector)
	  SELECT 'Just Pho Fun','1 Main St. W, Hamilton, ON','Food and Beverage'
UNION SELECT 'Food and Stuff','2 Main St. W, Hamilton, ON','Retail'
UNION SELECT 'Tequila Mockingbird','3 Main St. W, Hamilton, ON','Bars and Nightclubs'
UNION SELECT 'Austin Flowers','4 Main St. W, Hamilton, ON','Floral'
UNION SELECT 'Knead Pizza','5 Main St. W,Hamilton, ON','Food and Beverage';

INSERT INTO Customer_Service_Representative (Name)
		SELECT 'Natesh'
UNION	SELECT 'Sanket'
UNION	SELECT 'Lois'
UNION	SELECT 'Diqing';

INSERT INTO Client (Company_ID, Title,Client_Name, Email_Address, Phone_Number, Physical_Address, Notes)
	  	  SELECT 1,'Mr.','Christopher','christopher@gmail.com','2261234567','1 Hamiton Rd., Hamilton, ON','Frequent client'
UNION SELECT 1,'Mr.','Chris','chris@gmail.com','2262345678','2 Hamiton Rd., Hamilton, ON',NULL
UNION SELECT 2,'Ms.','Christine','christine@gmail.com','2263456789','3 Hamiton Rd., Hamilton, ON','Frequent client'
UNION SELECT 2,'Mr.','Topher','topher@gmail.com','2264567890','4 Hamiton Rd., Hamilton, ON',NULL
UNION SELECT 3,'Mrs.','Christo','christo@gmail.com','2265678901','5 Hamiton Rd., Hamilton, ON',NULL
UNION SELECT 3,'Mr.','Christoph','christoph@gmail.com','2266789012','6 Hamiton Rd., Hamilton, ON','New client'
UNION SELECT 4,'Mr.','Christof','christof@gmail.com','2267890123','7 Hamiton Rd., Hamilton, ON','New client'
UNION SELECT 4,'Mr.','Chip','chip@gmail.com','2268901234','8 Hamiton Rd., Hamilton, ON',NULL
UNION SELECT 5,'Mr.','Khris','khris@gmail.com','2269012345','9 Hamiton Rd., Hamilton, ON',NULL
UNION SELECT 5,'Ms.','Christina','christina@gmail.com','2260123456','10 Hamiton Rd., Hamilton, ON',NULL;

INSERT INTO `Case` (Client_ID, Rep_ID, Details, Type)
	  SELECT 1,1,'Noodle and soup ratio is off','Product Quality Issues'
UNION SELECT 2,2,'Service was not prompt','Quality of Service Issues'
UNION SELECT 3,3,'Bought product, but it doesn''t do what it''s supposed to do','Product Quality Issues'
UNION SELECT 4,4,'Unable to get a refund on a product','Refund Issues'
UNION SELECT 5,1,'Charged the incorrect amount','Billing Issues'
UNION SELECT 6,1,'Rude service','Quality of Service Issues'
UNION SELECT 7,2,'Flowers weren''t delivered','Delivery Issues'
UNION SELECT 8,3,'Wrong mix of flower choices','Product Quality Issues'
UNION SELECT 9,4,'Pizza delivery time was too long','Delivery Issues'
UNION SELECT 10,3,'Got order wrong','Product Quality Issues'

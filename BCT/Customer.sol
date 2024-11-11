//SPDX-License-Identifier:MIT
pragma solidity ^0.8.0;

contract CustomerData{
    struct Customer{
        uint id;
        string name;
        string email;
        uint balance;
    }

    Customer[] public customers;

    address public owner;

    event EtherReceived(address sender,uint amount); 

    constructor() {
        owner = msg.sender;
    }

    modifier onlyOwner() {
        require(msg.sender == owner, "Only Owner can add Customers");
        _;
    }

    fallback() external payable {
        emit EtherReceived(msg.sender, msg.value);
        
    }

    receive() external payable {
        emit EtherReceived(msg.sender, msg.value);

    }

    function addCustomer(uint _id,string memory _name,string memory _email,uint _balance) public onlyOwner {
        customers.push(Customer(_id,_name,_email,_balance));
    } 

    function getCustomer(uint index) public view returns(uint,string memory ,string memory,uint) {
        require(index < customers.length,"Invalid index");
        Customer memory cust = customers[index];
        return (cust.id,cust.name,cust.email,cust.balance);
    }

    function getTotalCustomers() public view returns(uint total) {
        return customers.length;
    }
}
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentRegister{
    struct Student{
        string name;
        uint256 age;
        uint256 rollno;
    }

    Student[] private students;

    event StudentAdded(string name,uint256 age,uint256 rollno);
    event ReceiveEther(address indexed sender,uint256 value);

    fallback() external payable{
        emit ReceiveEther(msg.sender,msg.value);
    }

    function addStudent(string memory name,uint256 age,uint256 rollno) public{
        students.push(Student(name,age,rollno));
        emit StudentAdded(name, age, rollno);
    }

    function getStudent(uint256 index) public view returns(string memory,uint256,uint256){
        require(index < students.length,"Out of bound");
        return (students[index].name,students[index].age,students[index].rollno);
    }

    function getStudentCount() public view returns(uint256) {
        return students.length;
    }

    receive() external payable {
        emit ReceiveEther(msg.sender, msg.value);
    }
}
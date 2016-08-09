-- phpMyAdmin SQL Dump
-- version 2.11.9.4
-- http://www.phpmyadmin.net
--
-- Host: oniddb
-- Generation Time: Jul 28, 2016 at 10:53 PM
-- Server version: 5.5.49
-- PHP Version: 5.2.6-1+lenny16

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: cs290 su2016 RPS
--

-- --------------------------------------------------------

--
-- Table structure for table `Scores`
--

CREATE TABLE IF NOT EXISTS `Scores` (
  `username` varchar(10) NOT NULL,
  `game` varchar(10) NOT NULL,
  `score` int(10) DEFAULT '100',
  `wins` int(10) DEFAULT '0',
  `loses` int(10) DEFAULT '0',
  PRIMARY KEY (`username`,`game`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Scores`
--

INSERT INTO `Scores` (`username`, `game`, `score`, `wins`, `loses`) VALUES
('benny', 'hilo', 100, 0, 0),
('benny', 'rps', 329, 4, 10),
('benny', 'tictactoe', 50, 6, 10),
('ducky', 'hilo', 100, 0, 0),
('ducky', 'rps', 100, 0, 0),
('joey15', 'rps', 350, 15, 16),
('jojo', 'rps', 15000, 155, 20),
('jojo', 'tictactoe', 95, 10, 15),
('rose', 'hilo', 100, 0, 0),
('rose', 'rps', 500, 50, 47),
('tiger', 'hilo', 300, 12, 30),
('tiger', 'rps', 25, 3, 6),
('tommy', 'rps', 150, 1, 0);

-- --------------------------------------------------------

--
-- Table structure for table `Users`
--

CREATE TABLE IF NOT EXISTS `Users` (
  `username` varchar(10) NOT NULL,
  `password` varchar(40) NOT NULL,
  `firstName` varchar(20) NOT NULL,
  `lastName` varchar(20) NOT NULL,
  `email` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`username`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Users`
--

INSERT INTO `Users` (`username`, `password`, `firstName`, `lastName`, `email`) VALUES
('ducky', 'UofO16', 'Donald', 'McDuck', 'don@uo.edu'),
('benny', 'Osu2016', 'Ben', 'Beaver', 'ben@osu.edu'),
('rose', 'Abc123', 'Jane', 'Doe', 'jado@gmail.com');

-- MySQL dump 10.13  Distrib 8.0.32, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: city_schools
-- ------------------------------------------------------
-- Server version	8.0.32

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `classes`
--

DROP TABLE IF EXISTS `classes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `classes` (
  `IdClass` int NOT NULL AUTO_INCREMENT,
  `IdSchool` int NOT NULL,
  `ClassName` varchar(10) NOT NULL,
  `ClassTeacher` varchar(45) NOT NULL,
  `TeachersPhone` varchar(12) NOT NULL,
  PRIMARY KEY (`IdClass`),
  UNIQUE KEY `IdClass_UNIQUE` (`IdClass`),
  KEY `IdSchool_idx` (`IdSchool`),
  CONSTRAINT `IdSchool` FOREIGN KEY (`IdSchool`) REFERENCES `schools` (`IdSchool`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `classes`
--

LOCK TABLES `classes` WRITE;
/*!40000 ALTER TABLE `classes` DISABLE KEYS */;
INSERT INTO `classes` VALUES (1,5,'1А','Иванова О.И.','89507856425'),(2,4,'1А','Орехова Е.В.','89995478682'),(3,4,'10Б','Перелыгина Н.К.','85674526325');
/*!40000 ALTER TABLE `classes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `schools`
--

DROP TABLE IF EXISTS `schools`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `schools` (
  `IdSchool` int NOT NULL AUTO_INCREMENT,
  `SchoolName` varchar(45) NOT NULL,
  `SchoolType` varchar(45) NOT NULL,
  `Street` varchar(45) NOT NULL,
  `HouseNum` varchar(10) NOT NULL,
  PRIMARY KEY (`IdSchool`),
  UNIQUE KEY `id_schools_UNIQUE` (`IdSchool`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `schools`
--

LOCK TABLES `schools` WRITE;
/*!40000 ALTER TABLE `schools` DISABLE KEYS */;
INSERT INTO `schools` VALUES (4,'49','Средняя','Мира','58'),(5,'15','Физико-математическая','Российская','15');
/*!40000 ALTER TABLE `schools` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `students`
--

DROP TABLE IF EXISTS `students`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `students` (
  `IdStudent` int NOT NULL AUTO_INCREMENT,
  `IdClass` int NOT NULL,
  `FamilyName` varchar(45) NOT NULL,
  `BornYear` varchar(4) NOT NULL,
  `JoinYear` varchar(4) NOT NULL,
  `Sex` varchar(10) NOT NULL,
  PRIMARY KEY (`IdStudent`),
  UNIQUE KEY `IdStudent_UNIQUE` (`IdStudent`),
  KEY `IdClass_idx` (`IdClass`),
  CONSTRAINT `IdClass` FOREIGN KEY (`IdClass`) REFERENCES `classes` (`IdClass`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `students`
--

LOCK TABLES `students` WRITE;
/*!40000 ALTER TABLE `students` DISABLE KEYS */;
INSERT INTO `students` VALUES (1,1,'Авакумов','2015','2022','Мужской'),(2,1,'Сидорова','2015','2022','Женский'),(3,2,'Петров','2015','2023','Мужской'),(4,2,'Демченко','2015','2023','Женский'),(5,3,'Сидоров','2006','2012','Мальчик'),(6,3,'Чупина','2006','2012','Девочка');
/*!40000 ALTER TABLE `students` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-03-10  3:34:36

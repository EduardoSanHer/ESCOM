-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Servidor: localhost
-- Tiempo de generación: 20-12-2021 a las 22:56:53
-- Versión del servidor: 8.0.23
-- Versión de PHP: 8.0.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `tdaweb_proyecto`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `administrador`
--

CREATE TABLE `administrador` (
  `idAdministrador` int NOT NULL,
  `Clave` varchar(45) NOT NULL,
  `Nombre` varchar(45) NOT NULL,
  `ApellidoPaterno` varchar(45) NOT NULL,
  `ApellidoMaterno` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `administrador`
--

INSERT INTO `administrador` (`idAdministrador`, `Clave`, `Nombre`, `ApellidoPaterno`, `ApellidoMaterno`) VALUES
(1, '3aee06eaf5d8299ebdfb5ddd5001c627', 'JUAN CARLOS', 'ALVAREZ', 'VELAZQUEZ'),
(2, '613d3c0c2679ed2132900769ba1defc5', 'ANTONIO', 'ARCE', 'GUDNO'),
(3, '0ba606a1645a8218e0ce0c48f297226d', 'HUGO EDGAR', 'MELO', 'MEDRANO'),
(4, 'fc4d2f4cf41389d92cbb91569d682734', 'JUAN', 'REGALADO', 'RAMOS'),
(5, 'ae6263ba7189ad446879880378e9af37', 'JULIO CESAR', 'SANDOVAL', 'PEREZ');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `alumno`
--

CREATE TABLE `alumno` (
  `NumBoleta` int NOT NULL,
  `Clave` varchar(45) NOT NULL,
  `Nombre_s` varchar(45) NOT NULL,
  `ApellidoPaterno` varchar(45) NOT NULL,
  `ApellidoMaterno` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `alumno`
--

INSERT INTO `alumno` (`NumBoleta`, `Clave`, `Nombre_s`, `ApellidoPaterno`, `ApellidoMaterno`) VALUES
(2020630600, '56c6590771265a610a32ab3343d9962b', 'JOSE ALFONSO', 'MARTINEZ', 'GUTIERREZ'),
(2020630601, 'af7a4a1e90b5c7dc4af3b604c45b6219', 'ANTONIO', 'ANGELES', 'RAMIREZ'),
(2020630602, 'ef49d4ae4ef8d8f16cc0c0fd235f3fc5', 'ISAIAS MANUEL', 'MORA', 'RAMIREZ'),
(2020630603, '6bbf6048ccce11ca7702681d0a092d20', 'HECTOR VLADIMIR', 'BARRETO', 'AYALA'),
(2020630604, 'f85fef6b8c32101dfff16bee57a2d2be', 'CARLOS ALBERTO', 'GUZMAN', 'TAVERA'),
(2020630605, '44c57ff0d9c34d842ec418552aece4b0', 'FELIPE DE JESUS', 'ESCOBAR', 'LOPEZ'),
(2020630606, '81ec765c7e693486859ed12e1bebf03d', 'LUIS FRANCISCO', 'ALVA', 'BELTRAN'),
(2020630607, '10d1fb9b15f9b40edef408c3cf7b5976', 'OMAR', 'ELVIRA', 'JIMENEZ'),
(2020630608, '50a967204248c6f3d8f88070958a5e09', 'DAVID BERNARDO', 'HERNANDEZ', 'GONZALEZ'),
(2020630609, '39c44f853d937270d5a36663cc91ffe5', 'CHRISTIAN FERNANDO', 'CASTILLO', 'GARCIA'),
(2020630610, 'dcdaa293840dc30203f179d442a4211c', 'LUIS CARLOS', 'PIMENTEL', 'ESCOBEDO'),
(2020630611, '9635e11fa71f91b5721a06e26237d630', 'JORGE DAVID', 'CASTAÑARES', 'TORRES'),
(2020630612, '5c546cd9f73c10cb61b55e3ab5d46923', 'MIRELLE GUADALUPE', 'RODRIGUEZ', 'ALAMILLA'),
(2020630613, '0e5428fd9a899df7ff0b7d41b3aecfc2', 'JOEL ENRIQUE', 'ESPEJEL', 'ZARATE'),
(2020630614, 'ed13df12b740667e1ced2337cfeba72c', 'GABRIEL', 'GARCIA', 'MERAZ'),
(2020630615, '2635d85380e2d6bd22c439d9d3116566', 'GEOVANY DANIEL', 'MONDRAGON', 'MEJIA'),
(2020630616, 'ade66b7a7cac8847be93315bdc5e40cd', 'ERIC EMMANUEL', 'NUNCIO', 'PULIDO'),
(2020630617, '226543f07a4950e5567a36a49ec286cb', 'JESUS FERNANDO', 'VACA', 'GARCIA'),
(2020630618, '540175d2167cc7a6638e51febff66e10', 'URIEL', 'ZAMORA', 'FRANCO'),
(2020630619, 'a7cc71cc669145eb7d85a87074334282', 'FRANCISCO JAVIER', 'JUAREZ', 'LUNA'),
(2020630620, 'ed8c0d4303d8c0e9be6fa33ce0ed4ea9', 'FRANCISCO', 'TRINIDAD', 'CRUZ');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `comentario`
--

CREATE TABLE `comentario` (
  `idComentario` int NOT NULL,
  `Comentariocol` varchar(180) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `comentario`
--

INSERT INTO `comentario` (`idComentario`, `Comentariocol`) VALUES
(20, 'Ya hace falta tener clases presenciales'),
(21, 'Extraño la ESCOM :c'),
(22, 'Las clases en línea en general tienen menor calidad'),
(23, 'No todo se puede enseñar en línea y esa modalidad no es para todos'),
(24, 'La poca calidad de los servicios de electricidad, internet y equipos a usar, hizo que la experiencia virtual  haya disminuido'),
(25, 'El hecho de la debilidad de la potencia del internet, hacía, por ejemplo, que se les pidiera a los alumnos que apagaran las cámaras'),
(26, 'Hay materias o temas de las asignaturas que son eminentemente prácticas.'),
(27, 'Los alumnos son inmaduros y no se toman con suficiente responsabilidad hacer un examen directo'),
(28, ' La obligación de tener que impartir clases de manera virtualha sidoun ejercicio más precario para los alumnos, que las clases presenciales.');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `encuesta`
--

CREATE TABLE `encuesta` (
  `Alumno_NumBoleta_Encuesta` int NOT NULL,
  `Materia_idMateria_Encuesta` varchar(4) NOT NULL,
  `Grupo_idGrupo_Encuesta` varchar(5) NOT NULL,
  `Respuesta1` int NOT NULL,
  `Respuesta2` int NOT NULL,
  `Respuesta3` int NOT NULL,
  `Respuesta4` int NOT NULL,
  `Respuesta5` int NOT NULL,
  `Fecha` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `encuesta`
--

INSERT INTO `encuesta` (`Alumno_NumBoleta_Encuesta`, `Materia_idMateria_Encuesta`, `Grupo_idGrupo_Encuesta`, `Respuesta1`, `Respuesta2`, `Respuesta3`, `Respuesta4`, `Respuesta5`, `Fecha`) VALUES
(2020630600, 'C333', '3CM15', 1, 5, 2, 4, 2, '2021-12-18'),
(2020630600, 'C335', '3CM11', 5, 3, 5, 2, 4, '2021-12-18'),
(2020630600, 'C361', '3CV12', 3, 2, 4, 4, 2, '2021-12-18'),
(2020630601, 'C101', '1CV11', 4, 2, 5, 2, 4, '2021-12-18'),
(2020630601, 'C216', '2CM11', 4, 2, 4, 3, 4, '2021-12-18'),
(2020630601, 'C218', '2CM11', 5, 2, 4, 4, 2, '2021-12-18'),
(2020630601, 'C220', '2CV13', 5, 3, 4, 4, 2, '2021-12-18'),
(2020630601, 'C222', '2CV15', 1, 3, 4, 4, 5, '2021-12-18'),
(2020630603, 'C222', '2CM14', 5, 2, 4, 2, 4, '2021-12-18'),
(2020630605, 'C221', '2CV15', 3, 1, 4, 3, 2, '2021-12-18'),
(2020630605, 'C224', '2CV13', 5, 2, 4, 4, 3, '2021-12-18'),
(2020630605, 'C225', '2CV14', 5, 1, 5, 3, 3, '2021-12-18'),
(2020630605, 'C334', '3CV16', 5, 2, 5, 1, 5, '2021-12-18'),
(2020630605, 'C403', '4CV13', 2, 4, 2, 5, 1, '2021-12-18'),
(2020630606, 'C331', '3CV11', 4, 3, 4, 2, 1, '2021-12-18'),
(2020630606, 'C333', '3CV18', 3, 3, 3, 3, 3, '2021-12-18'),
(2020630607, 'C332', '3CM15', 5, 2, 5, 2, 5, '2021-12-18'),
(2020630608, 'C327', '3CV12', 5, 2, 5, 2, 4, '2021-12-18'),
(2020630608, 'C405', '4CV12', 2, 4, 2, 4, 3, '2021-12-18'),
(2020630609, 'C222', '2CM16', 2, 5, 3, 3, 2, '2021-12-18'),
(2020630609, 'C225', '2CV15', 1, 4, 3, 3, 2, '2021-12-18'),
(2020630609, 'C328', '3CV16', 5, 2, 5, 4, 3, '2021-12-18'),
(2020630609, 'C331', '3CM19', 2, 3, 2, 3, 5, '2021-12-18'),
(2020630609, 'C342', '3CV14', 4, 2, 5, 3, 2, '2021-12-18'),
(2020630609, 'C380', '3CV15', 5, 2, 4, 4, 2, '2021-12-18'),
(2020630610, 'C224', '2CV16', 5, 2, 4, 2, 5, '2021-12-18'),
(2020630610, 'C349', '3CV18', 4, 2, 4, 2, 2, '2021-12-18'),
(2020630610, 'C380', '3CM16', 4, 2, 4, 2, 3, '2021-12-18');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `gm`
--

CREATE TABLE `gm` (
  `Grupo_idGrupo` varchar(5) NOT NULL,
  `Materia_idMateria_GM` varchar(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `gm`
--

INSERT INTO `gm` (`Grupo_idGrupo`, `Materia_idMateria_GM`) VALUES
('1CV11', 'C101'),
('2CM11', 'C215'),
('2CM11', 'C216'),
('2CV11', 'C216'),
('2CM11', 'C217'),
('2CM11', 'C218'),
('2CM12', 'C218'),
('2CV13', 'C220'),
('2CV14', 'C220'),
('2CV15', 'C221'),
('2CV17', 'C221'),
('2CM14', 'C222'),
('2CM16', 'C222'),
('2CV15', 'C222'),
('2CV13', 'C223'),
('2CV13', 'C224'),
('2CV16', 'C224'),
('2CV14', 'C225'),
('2CV15', 'C225'),
('3CV11', 'C327'),
('3CV12', 'C327'),
('3CV13', 'C327'),
('3CV16', 'C328'),
('3CV17', 'C328'),
('3CV18', 'C328'),
('3CV13', 'C330'),
('3CM19', 'C331'),
('3CV11', 'C331'),
('3CV12', 'C331'),
('3CM15', 'C332'),
('3CV14', 'C332'),
('3CV17', 'C332'),
('3CM15', 'C333'),
('3CM16', 'C333'),
('3CV18', 'C333'),
('3CM16', 'C334'),
('3CV16', 'C334'),
('3CV17', 'C334'),
('3CM11', 'C335'),
('3CM14', 'C335'),
('3CM19', 'C338'),
('3CV14', 'C342'),
('3CV18', 'C349'),
('3CV16', 'C351'),
('3CV15', 'C352'),
('3CM12', 'C358'),
('3CV12', 'C361'),
('3CM15', 'C380'),
('3CM16', 'C380'),
('3CV15', 'C380'),
('3CV17', 'C380'),
('4CV11', 'C401'),
('4CV13', 'C401'),
('4CV11', 'C403'),
('4CV13', 'C403'),
('4CM13', 'C404'),
('4CV11', 'C404'),
('4CV15', 'C404'),
('4CM12', 'C405'),
('4CM14', 'C405'),
('4CV11', 'C405'),
('4CV12', 'C405');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `grupo`
--

CREATE TABLE `grupo` (
  `idGrupo` varchar(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `grupo`
--

INSERT INTO `grupo` (`idGrupo`) VALUES
('1CV11'),
('1CV15'),
('2CM11'),
('2CM12'),
('2CM14'),
('2CM16'),
('2CV11'),
('2CV13'),
('2CV14'),
('2CV15'),
('2CV16'),
('2CV17'),
('3CM11'),
('3CM12'),
('3CM14'),
('3CM15'),
('3CM16'),
('3CM19'),
('3CV11'),
('3CV12'),
('3CV13'),
('3CV14'),
('3CV15'),
('3CV16'),
('3CV17'),
('3CV18'),
('4CM12'),
('4CM13'),
('4CM14'),
('4CV11'),
('4CV12'),
('4CV13'),
('4CV15');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `inscripcion`
--

CREATE TABLE `inscripcion` (
  `Alumno_NumBoleta_Inscripcion` int NOT NULL,
  `Materia_idMateria_Inscripcion` varchar(4) NOT NULL,
  `Grupo_idGrupo_Inscripcion` varchar(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `inscripcion`
--

INSERT INTO `inscripcion` (`Alumno_NumBoleta_Inscripcion`, `Materia_idMateria_Inscripcion`, `Grupo_idGrupo_Inscripcion`) VALUES
(2020630601, 'C101', '1CV11'),
(2020630604, 'C215', '2CM11'),
(2020630601, 'C216', '2CM11'),
(2020630604, 'C216', '2CV11'),
(2020630604, 'C217', '2CM11'),
(2020630601, 'C218', '2CM11'),
(2020630614, 'C218', '2CM12'),
(2020630616, 'C218', '2CM12'),
(2020630601, 'C220', '2CV13'),
(2020630612, 'C220', '2CV14'),
(2020630605, 'C221', '2CV15'),
(2020630612, 'C221', '2CV17'),
(2020630601, 'C222', '2CV15'),
(2020630603, 'C222', '2CM14'),
(2020630604, 'C222', '2CV15'),
(2020630609, 'C222', '2CM16'),
(2020630612, 'C222', '2CM14'),
(2020630604, 'C223', '2CV13'),
(2020630605, 'C224', '2CV13'),
(2020630610, 'C224', '2CV16'),
(2020630604, 'C225', '2CV14'),
(2020630605, 'C225', '2CV14'),
(2020630609, 'C225', '2CV15'),
(2020630608, 'C327', '3CV12'),
(2020630611, 'C327', '3CV13'),
(2020630620, 'C327', '3CV11'),
(2020630609, 'C328', '3CV16'),
(2020630617, 'C328', '3CV17'),
(2020630619, 'C328', '3CV18'),
(2020630620, 'C328', '3CV18'),
(2020630611, 'C330', '3CV13'),
(2020630606, 'C331', '3CV11'),
(2020630609, 'C331', '3CM19'),
(2020630611, 'C331', '3CV12'),
(2020630607, 'C332', '3CM15'),
(2020630611, 'C332', '3CV17'),
(2020630615, 'C332', '3CV14'),
(2020630600, 'C333', '3CM15'),
(2020630606, 'C333', '3CV18'),
(2020630611, 'C333', '3CM16'),
(2020630620, 'C333', '3CM15'),
(2020630602, 'C334', '3CM16'),
(2020630605, 'C334', '3CV16'),
(2020630614, 'C334', '3CV17'),
(2020630620, 'C334', '3CV16'),
(2020630600, 'C335', '3CM11'),
(2020630618, 'C335', '3CM14'),
(2020630613, 'C338', '3CM19'),
(2020630609, 'C342', '3CV14'),
(2020630610, 'C349', '3CV18'),
(2020630614, 'C351', '3CV16'),
(2020630616, 'C352', '3CV15'),
(2020630617, 'C358', '3CM12'),
(2020630600, 'C361', '3CV12'),
(2020630609, 'C380', '3CV15'),
(2020630610, 'C380', '3CM16'),
(2020630611, 'C380', '3CV17'),
(2020630612, 'C380', '3CM15'),
(2020630616, 'C401', '4CV11'),
(2020630619, 'C401', '4CV11'),
(2020630620, 'C401', '4CV13'),
(2020630605, 'C403', '4CV13'),
(2020630617, 'C403', '4CV11'),
(2020630613, 'C404', '4CV11'),
(2020630617, 'C404', '4CM13'),
(2020630618, 'C404', '4CV15'),
(2020630608, 'C405', '4CV12'),
(2020630615, 'C405', '4CV11'),
(2020630618, 'C405', '4CM14'),
(2020630620, 'C405', '4CM12');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `materia`
--

CREATE TABLE `materia` (
  `idMateria` varchar(4) NOT NULL,
  `NombreMateria` varchar(80) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `materia`
--

INSERT INTO `materia` (`idMateria`, `NombreMateria`) VALUES
('C101', 'ANALISIS VECTORIAL'),
('C215', 'FUNDAMENTOS DE DISEÑO DIGITAL'),
('C216', 'TEORIA COMPUTACIONAL'),
('C217', 'BASES DE DATOS'),
('C218', 'PROGRAMACION ORIENTADA A OBJETOS'),
('C220', 'REDES DE COMPUTADORAS'),
('C221', 'DISEÑO DE SISTEMAS DIGITALES'),
('C222', 'PROBABILIDAD Y ESTADISTICA'),
('C223', 'SISTEMAS OPERATIVOS'),
('C224', 'ANALISIS Y DISEÑO ORIENTADO A OBJETOS'),
('C225', 'TECNOLOGIAS PARA LA WEB'),
('C327', 'ARQUITECTURA DE COMPUTADORAS'),
('C328', 'COMPILADORES'),
('C330', 'ADMINISTRACION DE PROYECTOS'),
('C331', 'INSTRUMENTACION'),
('C332', 'TEORIA DE COMUNICACIONES Y SEÑALES'),
('C333', 'APLICACIONES PARA COMUNICACIONES DE RED'),
('C334', 'INTRODUCCION A LOS MICROCONTROLADORES'),
('C335', 'ANALISIS DE ALGORITMOS'),
('C338', 'CRYPTOGRAPHY'),
('C342', 'COMPUTER GRAPHICS'),
('C349', 'ARTIFICIAL INTELLIGENCE'),
('C351', 'APPLICATION DEVELOPMENT FOR MOBILE DEVICES'),
('C352', 'WEB APPLICATION DEVELOPMENT'),
('C358', 'ECONOMIC ENGINEERING'),
('C361', 'HIGH TECHNOLOGY ENTERPRISE MANAGEMENT'),
('C380', 'METODOS CUANTITATIVOS PARA LA TOMA DE DECISIONES'),
('C401', 'GESTION EMPRESARIAL'),
('C403', 'LIDERAZGO Y DESARROLLO PROFESIONAL'),
('C404', 'ADMINISTRACION DE SERVICIOS EN RED'),
('C405', 'DESARROLLO DE SISTEMAS DISTRIBUIDOS');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `pregunta`
--

CREATE TABLE `pregunta` (
  `idPregunta` int NOT NULL,
  `Preguntacol` varchar(180) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `pregunta`
--

INSERT INTO `pregunta` (`idPregunta`, `Preguntacol`) VALUES
(1, '¿Los contenidos fundamentales del programa de la asignatura se tratan suficientemente a lo largo del curso?'),
(2, '¿El profesor promueve la participación en clase?'),
(3, '¿Se utiliza para el aprendizaje las herramientas de interacción de las tecnologías actuales de la información?'),
(4, '¿La evaluación se ajusta a los contenidos trabajados durante el curso?'),
(5, '¿El nivel exigido en la evaluación se corresponde con el que se imparte en clase?');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `administrador`
--
ALTER TABLE `administrador`
  ADD PRIMARY KEY (`idAdministrador`);

--
-- Indices de la tabla `alumno`
--
ALTER TABLE `alumno`
  ADD PRIMARY KEY (`NumBoleta`);

--
-- Indices de la tabla `comentario`
--
ALTER TABLE `comentario`
  ADD PRIMARY KEY (`idComentario`);

--
-- Indices de la tabla `encuesta`
--
ALTER TABLE `encuesta`
  ADD PRIMARY KEY (`Alumno_NumBoleta_Encuesta`,`Materia_idMateria_Encuesta`,`Grupo_idGrupo_Encuesta`),
  ADD KEY `Materia_idMateria_idx` (`Materia_idMateria_Encuesta`),
  ADD KEY `Grupo_idGrupo_Encuesta_idx` (`Grupo_idGrupo_Encuesta`);

--
-- Indices de la tabla `gm`
--
ALTER TABLE `gm`
  ADD PRIMARY KEY (`Grupo_idGrupo`,`Materia_idMateria_GM`),
  ADD KEY `Materia_idMateria_idx` (`Materia_idMateria_GM`);

--
-- Indices de la tabla `grupo`
--
ALTER TABLE `grupo`
  ADD PRIMARY KEY (`idGrupo`);

--
-- Indices de la tabla `inscripcion`
--
ALTER TABLE `inscripcion`
  ADD PRIMARY KEY (`Alumno_NumBoleta_Inscripcion`,`Materia_idMateria_Inscripcion`,`Grupo_idGrupo_Inscripcion`),
  ADD KEY `Materia_idMateria_idx` (`Materia_idMateria_Inscripcion`),
  ADD KEY `Grupo_idGrupo_Inscripcion_idx` (`Grupo_idGrupo_Inscripcion`);

--
-- Indices de la tabla `materia`
--
ALTER TABLE `materia`
  ADD PRIMARY KEY (`idMateria`);

--
-- Indices de la tabla `pregunta`
--
ALTER TABLE `pregunta`
  ADD PRIMARY KEY (`idPregunta`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `administrador`
--
ALTER TABLE `administrador`
  MODIFY `idAdministrador` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT de la tabla `alumno`
--
ALTER TABLE `alumno`
  MODIFY `NumBoleta` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2020630621;

--
-- AUTO_INCREMENT de la tabla `comentario`
--
ALTER TABLE `comentario`
  MODIFY `idComentario` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=33;

--
-- AUTO_INCREMENT de la tabla `pregunta`
--
ALTER TABLE `pregunta`
  MODIFY `idPregunta` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `encuesta`
--
ALTER TABLE `encuesta`
  ADD CONSTRAINT `Alumno_NumBoleta_Encuesta` FOREIGN KEY (`Alumno_NumBoleta_Encuesta`) REFERENCES `alumno` (`NumBoleta`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Grupo_idGrupo_Encuesta` FOREIGN KEY (`Grupo_idGrupo_Encuesta`) REFERENCES `grupo` (`idGrupo`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Materia_idMateria_Encuesta` FOREIGN KEY (`Materia_idMateria_Encuesta`) REFERENCES `materia` (`idMateria`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Filtros para la tabla `gm`
--
ALTER TABLE `gm`
  ADD CONSTRAINT `Grupo_idGrupo` FOREIGN KEY (`Grupo_idGrupo`) REFERENCES `grupo` (`idGrupo`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Materia_idMateria_GM` FOREIGN KEY (`Materia_idMateria_GM`) REFERENCES `materia` (`idMateria`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Filtros para la tabla `inscripcion`
--
ALTER TABLE `inscripcion`
  ADD CONSTRAINT `Alumno_NumBoleta_Inscripcion` FOREIGN KEY (`Alumno_NumBoleta_Inscripcion`) REFERENCES `alumno` (`NumBoleta`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Grupo_idGrupo_Inscripcion` FOREIGN KEY (`Grupo_idGrupo_Inscripcion`) REFERENCES `grupo` (`idGrupo`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Materia_idMateria_Inscripcion` FOREIGN KEY (`Materia_idMateria_Inscripcion`) REFERENCES `materia` (`idMateria`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

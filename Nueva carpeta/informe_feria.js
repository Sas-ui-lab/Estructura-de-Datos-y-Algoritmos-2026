const {
  Document, Packer, Paragraph, TextRun, Table, TableRow, TableCell,
  Header, Footer, AlignmentType, HeadingLevel, BorderStyle, WidthType,
  ShadingType, VerticalAlign, PageNumber, PageBreak, LevelFormat,
  TabStopType, TabStopPosition
} = require('docx');
const fs = require('fs');

const VERDE = "1A6B2A";
const VERDE_CLARO = "D4EDDA";
const VERDE_MEDIO = "A8D5B5";
const AMARILLO = "FFF3CD";
const GRIS_CLARO = "F5F5F5";
const BLANCO = "FFFFFF";

const border = { style: BorderStyle.SINGLE, size: 1, color: "BBBBBB" };
const borders = { top: border, bottom: border, left: border, right: border };

function h1(text) {
  return new Paragraph({
    heading: HeadingLevel.HEADING_1,
    spacing: { before: 360, after: 180 },
    border: { bottom: { style: BorderStyle.SINGLE, size: 4, color: VERDE, space: 6 } },
    children: [new TextRun({ text, bold: true, size: 28, color: VERDE, font: "Arial" })]
  });
}

function h2(text) {
  return new Paragraph({
    heading: HeadingLevel.HEADING_2,
    spacing: { before: 280, after: 120 },
    children: [new TextRun({ text, bold: true, size: 24, color: "2C5F2E", font: "Arial" })]
  });
}

function h3(text) {
  return new Paragraph({
    heading: HeadingLevel.HEADING_3,
    spacing: { before: 200, after: 80 },
    children: [new TextRun({ text, bold: true, size: 22, color: "3A7D44", font: "Arial" })]
  });
}

function p(text, opts = {}) {
  return new Paragraph({
    alignment: AlignmentType.JUSTIFIED,
    spacing: { before: 80, after: 80, line: 276 },
    children: [new TextRun({ text, size: 22, font: "Arial", ...opts })]
  });
}

function bullet(text) {
  return new Paragraph({
    numbering: { reference: "bullets", level: 0 },
    spacing: { before: 40, after: 40 },
    children: [new TextRun({ text, size: 22, font: "Arial" })]
  });
}

function numbered(text) {
  return new Paragraph({
    numbering: { reference: "numbers", level: 0 },
    spacing: { before: 40, after: 40 },
    children: [new TextRun({ text, size: 22, font: "Arial" })]
  });
}

function space(n = 1) {
  return Array.from({ length: n }, () => new Paragraph({ children: [new TextRun("")], spacing: { before: 60, after: 60 } }));
}

function infoBox(label, value, fillColor = VERDE_CLARO) {
  return new TableRow({
    children: [
      new TableCell({
        borders,
        width: { size: 3000, type: WidthType.DXA },
        shading: { fill: VERDE_MEDIO, type: ShadingType.CLEAR },
        margins: { top: 80, bottom: 80, left: 120, right: 120 },
        children: [new Paragraph({ children: [new TextRun({ text: label, bold: true, size: 20, font: "Arial", color: "1A3C1A" })] })]
      }),
      new TableCell({
        borders,
        width: { size: 6360, type: WidthType.DXA },
        shading: { fill: fillColor, type: ShadingType.CLEAR },
        margins: { top: 80, bottom: 80, left: 120, right: 120 },
        children: [new Paragraph({ children: [new TextRun({ text: value, size: 20, font: "Arial" })] })]
      })
    ]
  });
}

const doc = new Document({
  numbering: {
    config: [
      {
        reference: "bullets",
        levels: [{
          level: 0, format: LevelFormat.BULLET, text: "\u2022", alignment: AlignmentType.LEFT,
          style: { paragraph: { indent: { left: 720, hanging: 360 } } }
        }]
      },
      {
        reference: "numbers",
        levels: [{
          level: 0, format: LevelFormat.DECIMAL, text: "%1.", alignment: AlignmentType.LEFT,
          style: { paragraph: { indent: { left: 720, hanging: 360 } } }
        }]
      }
    ]
  },
  styles: {
    default: { document: { run: { font: "Arial", size: 22 } } },
    paragraphStyles: [
      {
        id: "Heading1", name: "Heading 1", basedOn: "Normal", next: "Normal", quickFormat: true,
        run: { size: 28, bold: true, font: "Arial", color: VERDE },
        paragraph: { spacing: { before: 360, after: 180 }, outlineLevel: 0 }
      },
      {
        id: "Heading2", name: "Heading 2", basedOn: "Normal", next: "Normal", quickFormat: true,
        run: { size: 24, bold: true, font: "Arial", color: "2C5F2E" },
        paragraph: { spacing: { before: 280, after: 120 }, outlineLevel: 1 }
      },
      {
        id: "Heading3", name: "Heading 3", basedOn: "Normal", next: "Normal", quickFormat: true,
        run: { size: 22, bold: true, font: "Arial", color: "3A7D44" },
        paragraph: { spacing: { before: 200, after: 80 }, outlineLevel: 2 }
      }
    ]
  },
  sections: [{
    properties: {
      page: {
        size: { width: 11906, height: 16838 },
        margin: { top: 1440, right: 1260, bottom: 1440, left: 1260 }
      }
    },
    headers: {
      default: new Header({
        children: [
          new Paragraph({
            alignment: AlignmentType.CENTER,
            border: { bottom: { style: BorderStyle.SINGLE, size: 4, color: VERDE, space: 6 } },
            children: [
              new TextRun({ text: "UNIVERSIDAD NACIONAL AGRARIA DE LA SELVA  |  FIIA", size: 16, font: "Arial", color: "555555" })
            ]
          })
        ]
      })
    },
    footers: {
      default: new Footer({
        children: [
          new Paragraph({
            alignment: AlignmentType.CENTER,
            border: { top: { style: BorderStyle.SINGLE, size: 4, color: VERDE, space: 6 } },
            children: [
              new TextRun({ text: "Informe Oficial  |  Feria de Ingeniería y Tecnología Alimentaria 2026  |  Página ", size: 16, font: "Arial", color: "777777" }),
              new TextRun({ children: [PageNumber.CURRENT], size: 16, font: "Arial", color: "777777" }),
              new TextRun({ text: " de ", size: 16, font: "Arial", color: "777777" }),
              new TextRun({ children: [PageNumber.TOTAL_PAGES], size: 16, font: "Arial", color: "777777" })
            ]
          })
        ]
      })
    },
    children: [

      // ─── PORTADA ───────────────────────────────────────────────────
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 480, after: 120 },
        children: [new TextRun({ text: "UNIVERSIDAD NACIONAL AGRARIA DE LA SELVA", bold: true, size: 28, font: "Arial", color: VERDE })]
      }),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 40, after: 40 },
        children: [new TextRun({ text: "Facultad de Ingeniería en Industrias Alimentarias", size: 24, font: "Arial", color: "3A3A3A" })]
      }),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 40, after: 40 },
        children: [new TextRun({ text: "Tingo María, Perú", size: 22, font: "Arial", color: "555555" })]
      }),

      ...space(2),

      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 120, after: 40 },
        children: [new TextRun({ text: "INFORME OFICIAL DE EVENTO", bold: true, size: 36, font: "Arial", color: BLANCO, highlight: undefined })]
      }),

      // Caja de título destacada
      new Table({
        width: { size: 9386, type: WidthType.DXA },
        columnWidths: [9386],
        rows: [
          new TableRow({
            children: [
              new TableCell({
                borders,
                shading: { fill: VERDE, type: ShadingType.CLEAR },
                margins: { top: 200, bottom: 200, left: 300, right: 300 },
                children: [
                  new Paragraph({
                    alignment: AlignmentType.CENTER,
                    children: [new TextRun({ text: "FERIA DE INGENIERÍA Y TECNOLOGÍA", bold: true, size: 32, font: "Arial", color: BLANCO })]
                  }),
                  new Paragraph({
                    alignment: AlignmentType.CENTER,
                    children: [new TextRun({ text: "ALIMENTARIA 2026", bold: true, size: 32, font: "Arial", color: BLANCO })]
                  }),
                  new Paragraph({
                    alignment: AlignmentType.CENTER,
                    spacing: { before: 120 },
                    children: [new TextRun({ text: '"Innovación • Tecnología • Nutrición • Futuro"', size: 22, font: "Arial", color: "CCFFCC", italics: true })]
                  })
                ]
              })
            ]
          })
        ]
      }),

      ...space(1),

      new Table({
        width: { size: 9386, type: WidthType.DXA },
        columnWidths: [9386],
        rows: [
          new TableRow({
            children: [
              new TableCell({
                borders,
                shading: { fill: AMARILLO, type: ShadingType.CLEAR },
                margins: { top: 120, bottom: 120, left: 240, right: 240 },
                children: [
                  new Paragraph({
                    alignment: AlignmentType.CENTER,
                    children: [new TextRun({ text: "52.º Aniversario de la Facultad de Ingeniería en Industrias Alimentarias", bold: true, size: 22, font: "Arial", color: "5D4037" })]
                  }),
                  new Paragraph({
                    alignment: AlignmentType.CENTER,
                    children: [new TextRun({ text: "Jueves 4 de junio de 2026  |  Cochera UNAS (Puerta #2)", size: 20, font: "Arial", color: "5D4037" })]
                  })
                ]
              })
            ]
          })
        ]
      }),

      ...space(3),

      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 40, after: 40 },
        children: [new TextRun({ text: "Dirección General del Evento:", bold: true, size: 20, font: "Arial", color: "444444" })]
      }),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        children: [new TextRun({ text: "Dra. Elizabeth Susana Ordoñez Gómez", size: 22, font: "Arial", color: VERDE, bold: true })]
      }),
      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 80 },
        children: [new TextRun({ text: "Tingo María, junio de 2026", size: 20, font: "Arial", color: "666666" })]
      }),

      // Salto de página
      new Paragraph({ children: [new PageBreak()] }),

      // ─── SECCIÓN 1: DATOS GENERALES ────────────────────────────────
      h1("1. DATOS GENERALES DEL EVENTO"),
      ...space(1),

      new Table({
        width: { size: 9386, type: WidthType.DXA },
        columnWidths: [3000, 6386],
        rows: [
          infoBox("Nombre oficial", "Feria de Ingeniería y Tecnología Alimentaria 2026"),
          infoBox("Lema institucional", "Innovación • Tecnología • Nutrición • Futuro", AMARILLO),
          infoBox("Fecha de ejecución", "Jueves 4 de junio de 2026"),
          infoBox("Hora de inauguración", "08:00 a. m.", AMARILLO),
          infoBox("Lugar", "Cochera del Comedor Universitario – UNAS (Puerta #2)"),
          infoBox("Dirección general", "Dra. Elizabeth Susana Ordoñez Gómez", AMARILLO),
          infoBox("Decano", "Dr. Roberto Dávila Trujillo"),
          infoBox("Institución organizadora", "Facultad de Ingeniería en Industrias Alimentarias – UNAS", AMARILLO),
          infoBox("Contexto", "52.º Aniversario de la FIIA"),
          infoBox("Modalidad", "Presencial – Campus Universitario UNAS", AMARILLO),
        ]
      }),

      ...space(1),

      // ─── SECCIÓN 2: ANTECEDENTES ───────────────────────────────────
      h1("2. ANTECEDENTES Y JUSTIFICACIÓN"),

      p("En el marco de las celebraciones por el 52.º aniversario de creación institucional de la Facultad de Ingeniería en Industrias Alimentarias (FIIA) de la Universidad Nacional Agraria de la Selva (UNAS), las autoridades académicas concibieron y ejecutaron la Feria de Ingeniería y Tecnología Alimentaria 2026 como una plataforma de articulación entre la formación académica, la investigación aplicada y el emprendimiento productivo."),
      ...space(1),
      p("Esta actividad responde a la necesidad institucional de crear espacios donde los estudiantes puedan demostrar las competencias adquiridas durante su formación profesional, conectar con el mercado local y generar experiencias reales de emprendimiento. Adicionalmente, la feria se concibe como un mecanismo de visibilización del potencial científico-tecnológico de la FIIA ante la comunidad universitaria, instituciones aliadas y el público en general."),
      ...space(1),
      p("La elección de la Cochera del Comedor Universitario como locación respondió a criterios técnicos precisos: su amplia superficie, la conectividad eléctrica disponible para los equipos de los expositores, y el flujo continuo de la comunidad estudiantil garantizaban una máxima afluencia de visitantes durante la jornada."),

      // ─── SECCIÓN 3: OBJETIVOS ──────────────────────────────────────
      h1("3. OBJETIVOS DEL EVENTO"),

      h2("3.1 Objetivo General"),
      p("Promover la innovación, el emprendimiento y la transferencia tecnológica en el sector de las industrias alimentarias, mediante la exhibición y comercialización de productos y proyectos desarrollados por la comunidad académica de la FIIA-UNAS, en el marco del 52.º aniversario institucional."),

      h2("3.2 Objetivos Específicos"),
      bullet("Brindar a los estudiantes un espacio real de exposición y comercialización de sus productos alimentarios innovadores."),
      bullet("Fomentar el espíritu emprendedor y la creatividad dentro de la comunidad universitaria de la FIIA."),
      bullet("Fortalecer los vínculos entre la universidad, el sector productivo y la ciudadanía de Tingo María."),
      bullet("Visibilizar los avances en investigación aplicada y desarrollo tecnológico de los laboratorios de la FIIA-UNAS."),
      bullet("Generar un mecanismo de evaluación práctica de las competencias profesionales de los estudiantes de pregrado."),
      bullet("Celebrar el 52.º aniversario de la Facultad mediante una actividad académica y productiva de alto impacto."),

      // ─── SECCIÓN 4: ORGANIZACIÓN ───────────────────────────────────
      h1("4. ESTRUCTURA ORGANIZATIVA"),

      p("El evento fue organizado bajo una estructura de comisiones académicas, con la Dra. Elizabeth Susana Ordoñez Gómez como Directora General del Evento. Las autoridades académicas —conformadas por el Decano Dr. Roberto Dávila Trujillo, el Director de Escuela, el Director Académico, docentes, el Centro Federado de Estudiantes y el personal administrativo— coordinaron de manera articulada cada fase del proceso."),
      ...space(1),

      new Table({
        width: { size: 9386, type: WidthType.DXA },
        columnWidths: [3000, 6386],
        rows: [
          new TableRow({
            children: [
              new TableCell({
                borders,
                columnSpan: 2,
                shading: { fill: VERDE, type: ShadingType.CLEAR },
                margins: { top: 100, bottom: 100, left: 180, right: 180 },
                children: [new Paragraph({ alignment: AlignmentType.CENTER, children: [new TextRun({ text: "COMITÉ ORGANIZADOR", bold: true, size: 22, color: BLANCO, font: "Arial" })] })]
              })
            ]
          }),
          infoBox("Presidenta / Directora General", "Dra. Elizabeth Susana Ordoñez Gómez"),
          infoBox("Autoridad Máxima", "Dr. Roberto Dávila Trujillo – Decano FIIA", AMARILLO),
          infoBox("Comisión Académica", "Dirección de Escuela + Dirección Académica"),
          infoBox("Comisión Estudiantil", "Centro Federado de Estudiantes FIIA", AMARILLO),
          infoBox("Comisión de Evaluación", "Docentes de la Facultad – Filtro Técnico de Inocuidad"),
          infoBox("Comisión Logística", "Personal Administrativo FIIA – UNAS", AMARILLO),
          infoBox("Cobertura Multimedia", "Equipo de Comunicaciones / Redes Sociales FIIA"),
        ]
      }),

      // ─── SECCIÓN 5: CONVOCATORIA ───────────────────────────────────
      h1("5. CONVOCATORIA Y PROCESO DE INSCRIPCIÓN"),

      h2("5.1 Perfiles de Participación"),
      p("La convocatoria fue abierta tanto a participantes internos como externos, bajo los siguientes perfiles:"),
      ...space(1),
      bullet("Estudiantes de pregrado de la FIIA-UNAS con proyectos de cursos, módulos de procesos productivos y trabajos de tesis."),
      bullet("Emprendimientos y startups universitarias orientadas al sector agroindustrial y de industrias alimentarias."),
      bullet("Líneas de investigación y laboratorios especializados de la UNAS con propuestas de transferencia tecnológica."),
      ...space(1),

      h2("5.2 Categorías Oficiales de Exhibición"),
      p("Para garantizar el orden temático y facilitar la navegación del público visitante, los proyectos y emprendimientos fueron agrupados en tres categorías:"),
      ...space(1),

      new Table({
        width: { size: 9386, type: WidthType.DXA },
        columnWidths: [500, 3300, 5586],
        rows: [
          new TableRow({
            children: [
              new TableCell({ borders, shading: { fill: VERDE, type: ShadingType.CLEAR }, margins: { top: 80, bottom: 80, left: 80, right: 80 },
                children: [new Paragraph({ alignment: AlignmentType.CENTER, children: [new TextRun({ text: "#", bold: true, color: BLANCO, size: 20, font: "Arial" })] })] }),
              new TableCell({ borders, shading: { fill: VERDE, type: ShadingType.CLEAR }, margins: { top: 80, bottom: 80, left: 120, right: 120 },
                children: [new Paragraph({ children: [new TextRun({ text: "Categoría", bold: true, color: BLANCO, size: 20, font: "Arial" })] })] }),
              new TableCell({ borders, shading: { fill: VERDE, type: ShadingType.CLEAR }, margins: { top: 80, bottom: 80, left: 120, right: 120 },
                children: [new Paragraph({ children: [new TextRun({ text: "Descripción", bold: true, color: BLANCO, size: 20, font: "Arial" })] })] })
            ]
          }),
          new TableRow({
            children: [
              new TableCell({ borders, shading: { fill: VERDE_CLARO, type: ShadingType.CLEAR }, margins: { top: 80, bottom: 80, left: 80, right: 80 }, width: { size: 500, type: WidthType.DXA },
                children: [new Paragraph({ alignment: AlignmentType.CENTER, children: [new TextRun({ text: "1", bold: true, size: 20, font: "Arial" })] })] }),
              new TableCell({ borders, shading: { fill: VERDE_CLARO, type: ShadingType.CLEAR }, margins: { top: 80, bottom: 80, left: 120, right: 120 }, width: { size: 3300, type: WidthType.DXA },
                children: [new Paragraph({ children: [new TextRun({ text: "Proyectos Innovadores y Nuevos Productos Alimentarios", bold: true, size: 20, font: "Arial" })] })] }),
              new TableCell({ borders, shading: { fill: VERDE_CLARO, type: ShadingType.CLEAR }, margins: { top: 80, bottom: 80, left: 120, right: 120 }, width: { size: 5586, type: WidthType.DXA },
                children: [new Paragraph({ children: [new TextRun({ text: "Productos originales con valor agregado, funcionalidad mejorada o formulación innovadora.", size: 20, font: "Arial" })] })] })
            ]
          }),
          new TableRow({
            children: [
              new TableCell({ borders, margins: { top: 80, bottom: 80, left: 80, right: 80 }, width: { size: 500, type: WidthType.DXA },
                children: [new Paragraph({ alignment: AlignmentType.CENTER, children: [new TextRun({ text: "2", bold: true, size: 20, font: "Arial" })] })] }),
              new TableCell({ borders, margins: { top: 80, bottom: 80, left: 120, right: 120 }, width: { size: 3300, type: WidthType.DXA },
                children: [new Paragraph({ children: [new TextRun({ text: "Tecnologías, Procesos e Investigación Aplicada", bold: true, size: 20, font: "Arial" })] })] }),
              new TableCell({ borders, margins: { top: 80, bottom: 80, left: 120, right: 120 }, width: { size: 5586, type: WidthType.DXA },
                children: [new Paragraph({ children: [new TextRun({ text: "Proyectos de investigación, prototipos tecnológicos, y demostración de procesos de transformación alimentaria.", size: 20, font: "Arial" })] })] })
            ]
          }),
          new TableRow({
            children: [
              new TableCell({ borders, shading: { fill: VERDE_CLARO, type: ShadingType.CLEAR }, margins: { top: 80, bottom: 80, left: 80, right: 80 }, width: { size: 500, type: WidthType.DXA },
                children: [new Paragraph({ alignment: AlignmentType.CENTER, children: [new TextRun({ text: "3", bold: true, size: 20, font: "Arial" })] })] }),
              new TableCell({ borders, shading: { fill: VERDE_CLARO, type: ShadingType.CLEAR }, margins: { top: 80, bottom: 80, left: 120, right: 120 }, width: { size: 3300, type: WidthType.DXA },
                children: [new Paragraph({ children: [new TextRun({ text: "Emprendimientos Universitarios", bold: true, size: 20, font: "Arial" })] })] }),
              new TableCell({ borders, shading: { fill: VERDE_CLARO, type: ShadingType.CLEAR }, margins: { top: 80, bottom: 80, left: 120, right: 120 }, width: { size: 5586, type: WidthType.DXA },
                children: [new Paragraph({ children: [new TextRun({ text: "Startups y microempresas universitarias con modelos de negocio en el sector agroindustrial.", size: 20, font: "Arial" })] })] })
            ]
          }),
        ]
      }),

      ...space(1),

      h2("5.3 Mecanismo de Inscripción"),
      p("El proceso de inscripción fue íntegramente digitalizado, permitiendo agilidad y control de aforo en tiempo real. Se implementaron los siguientes mecanismos:"),
      ...space(1),
      bullet("Distribución de código QR en afiches físicos instalados en los pabellones de la FIIA y áreas comunes del campus."),
      bullet("Enlace directo a formulario digital de inscripción (Microsoft Forms) difundido mediante canales digitales oficiales."),
      bullet("Modalidad de Inscripciones Limitadas para proteger la distribución física del Layout de stands y garantizar la disponibilidad del suministro eléctrico de la cochera."),
      bullet("Cierre automático de la convocatoria al alcanzar el cupo máximo de stands disponibles."),

      // ─── SECCIÓN 6: PLANIFICACIÓN ──────────────────────────────────
      new Paragraph({ children: [new PageBreak()] }),
      h1("6. FASES DE PLANIFICACIÓN Y EJECUCIÓN"),

      h2("6.1 Fase de Pre-Evento – Planificación"),
      p("La fase de planificación abarcó todas las acciones preparatorias necesarias para garantizar el desarrollo exitoso del evento. Se ejecutaron las siguientes actividades:"),
      ...space(1),

      h3("6.1.1 Diseño del Layout"),
      p("Se elaboró el plano de distribución física de los stands dentro de la Cochera del Comedor Universitario. El diseño priorizó la circulación fluida de visitantes, la accesibilidad a todos los puestos, la zonificación por categorías temáticas y la seguridad de los participantes. Se definieron las dimensiones de cada stand, los corredores de desplazamiento y las salidas de emergencia."),

      h3("6.1.2 Gestión de Canales de Registro"),
      p("El equipo de comunicaciones monitoreó en tiempo real el formulario virtual de inscripción, con el objeto de cerrar la convocatoria una vez alcanzado el cupo máximo de stands. Este control garantizó que la carga sobre el sistema eléctrico de la cochera no superara los límites técnicos permitidos."),

      h3("6.1.3 Filtro Técnico Académico"),
      p("La comisión evaluadora conformada por docentes especializados de la FIIA realizó una reunión de revisión técnica para verificar que todas las propuestas presentadas por los estudiantes cumplieran con los estándares de inocuidad alimentaria establecidos por la normativa vigente. Solo las propuestas que superaron esta revisión recibieron la asignación de un espacio físico en el evento."),

      h2("6.2 Fase de Evento – Ejecución"),
      p("La jornada de ejecución del evento se desarrolló bajo una coordinación precisa y un protocolo de actuación establecido con anterioridad."),
      ...space(1),

      h3("6.2.1 Protocolo de Apertura (08:00 a. m.)"),
      p("El maestro de ceremonias coordinó la recepción formal de las autoridades universitarias, el recorrido fotográfico inaugural por los stands y la declaración de apertura oficial del evento. La ceremonia de inauguración contó con la presencia del Decano Dr. Roberto Dávila Trujillo, el Director de Escuela, el Director Académico y representantes del Centro Federado de Estudiantes."),

      h3("6.2.2 Monitoreo Eléctrico y de Abastecimiento"),
      p("Durante toda la jornada, el equipo de logística realizó supervisión activa del suministro eléctrico, interviniendo en la resolución de percances técnicos con los equipos de procesamiento de los estudiantes. Se dispuso de personal técnico en alerta permanente para minimizar los tiempos de respuesta ante cualquier incidencia."),

      h3("6.2.3 Estrategia de Cobertura en Vivo"),
      p("El equipo de comunicaciones institucional coordinó las transmisiones en vivo y los registros multimedia del evento a través de los canales oficiales de la FIIA en redes sociales (Facebook y otras plataformas), visibilizando el evento en tiempo real hacia el exterior de la universidad y ampliando su alcance a la comunidad regional."),

      h2("6.3 Fase de Post-Evento – Cierre y Evaluación"),
      p("Concluida la jornada de exhibición y venta, se ejecutó un protocolo ordenado de desmontaje:"),
      ...space(1),
      bullet("Retiro ordenado y responsable de todos los productos alimentarios de los stands."),
      bullet("Desconexión segura de las redes eléctricas provisionales instaladas para el evento."),
      bullet("Limpieza profunda de la Cochera del Comedor Universitario para devolverla a su uso habitual en las condiciones en que fue recibida."),
      bullet("Recopilación de evidencias fotográficas, audiovisuales y registros de ventas para la elaboración del presente informe."),
      bullet("Reunión de evaluación interna del Comité Organizador para sistematizar aprendizajes y recomendaciones para futuras ediciones."),

      // ─── SECCIÓN 7: DESARROLLO DEL EVENTO ─────────────────────────
      new Paragraph({ children: [new PageBreak()] }),
      h1("7. DESARROLLO DEL EVENTO"),

      p("La Feria de Ingeniería y Tecnología Alimentaria 2026 se desarrolló con notable éxito el jueves 4 de junio de 2026 en la Cochera del Comedor Universitario de la UNAS (Puerta #2), registrando una destacada participación de emprendedores, estudiantes y público visitante a lo largo de toda la jornada."),
      ...space(1),
      p("Desde la ceremonia de inauguración a las 08:00 a. m., se evidenció un gran dinamismo en el recinto ferial. Los stands exhibieron una amplia variedad de productos alimentarios innovadores que reflejaron la solidez de la formación académica impartida en la FIIA. La disposición temática de las categorías permitió al público visitante recorrer ordenadamente las tres zonas de exhibición: productos innovadores, tecnologías aplicadas y emprendimientos universitarios."),
      ...space(1),
      p("Durante la jornada se registró un flujo constante y creciente de visitantes provenientes de la comunidad estudiantil de la UNAS, docentes, personal administrativo e instituciones externas. La ubicación estratégica de la cochera, en la zona de acceso principal de la Puerta #2, potenció la visibilidad del evento y facilitó el ingreso del público general."),
      ...space(1),

      new Table({
        width: { size: 9386, type: WidthType.DXA },
        columnWidths: [9386],
        rows: [
          new TableRow({
            children: [
              new TableCell({
                borders,
                shading: { fill: VERDE_CLARO, type: ShadingType.CLEAR },
                margins: { top: 180, bottom: 180, left: 240, right: 240 },
                children: [
                  new Paragraph({
                    alignment: AlignmentType.CENTER,
                    children: [new TextRun({ text: "RESULTADO DESTACADO", bold: true, size: 24, font: "Arial", color: VERDE })]
                  }),
                  new Paragraph({
                    alignment: AlignmentType.CENTER,
                    spacing: { before: 80 },
                    children: [new TextRun({ text: "La totalidad de los productos expuestos fue vendida durante la jornada, evidenciando la alta calidad e innovación de los productos, así como el dinamismo y capacidad emprendedora de los participantes.", size: 22, font: "Arial", italics: true })]
                  })
                ]
              })
            ]
          })
        ]
      }),

      ...space(1),
      p("Este resultado excepcional constituye un indicador objetivo del nivel de aceptación del público y de la pertinencia de los productos ofertados con respecto a las demandas del mercado local y regional."),

      // ─── SECCIÓN 8: PARTICIPANTES ──────────────────────────────────
      h1("8. PARTICIPANTES Y ACTORES CLAVE"),

      h2("8.1 Autoridades Universitarias"),
      bullet("Dr. Roberto Dávila Trujillo – Decano de la Facultad de Ingeniería en Industrias Alimentarias."),
      bullet("Director de Escuela Profesional de Ingeniería en Industrias Alimentarias."),
      bullet("Director Académico de la Facultad."),
      bullet("Dra. Elizabeth Susana Ordoñez Gómez – Directora General del Evento."),
      ...space(1),

      h2("8.2 Comunidad Académica"),
      bullet("Docentes de la FIIA: conformaron la comisión de evaluación técnica y brindaron acompañamiento a sus estudiantes durante la jornada."),
      bullet("Estudiantes universitarios del Centro Federado: participaron activamente en la organización, logística y difusión del evento."),
      bullet("Expositores-emprendedores: estudiantes de pregrado con proyectos inscritos en las tres categorías oficiales de exhibición."),
      ...space(1),

      h2("8.3 Personal Administrativo"),
      p("El personal administrativo de la FIIA brindó soporte operativo en la coordinación logística, la gestión del espacio físico y la atención a los requerimientos de los participantes."),
      ...space(1),

      h2("8.4 Público Asistente"),
      p("El evento convocó a una amplia y diversa audiencia que incluyó a la comunidad estudiantil general de la UNAS, familiares y amigos de los participantes, instituciones aliadas y ciudadanía de la región Huánuco interesada en la oferta de productos innovadores."),

      // ─── SECCIÓN 9: RESULTADOS ─────────────────────────────────────
      new Paragraph({ children: [new PageBreak()] }),
      h1("9. RESULTADOS E IMPACTO"),

      h2("9.1 Resultados Cualitativos"),
      bullet("Alta acogida del público visitante a lo largo de toda la jornada ferial."),
      bullet("Demostración exitosa del dinamismo, la creatividad y el espíritu emprendedor de la comunidad universitaria FIIA."),
      bullet("Fortalecimiento de la identidad institucional en el marco del 52.º aniversario de la Facultad."),
      bullet("Articulación efectiva entre la formación académica, la investigación aplicada y el emprendimiento productivo."),
      bullet("Visibilización del potencial científico-tecnológico de la FIIA-UNAS ante la comunidad regional."),
      bullet("Experiencia formativa integral para los estudiantes en gestión de emprendimientos y atención al cliente."),
      ...space(1),

      h2("9.2 Resultados Cuantitativos"),
      bullet("Venta total del 100% de los productos alimentarios expuestos en todos los stands participantes."),
      bullet("Cobertura multimedia en vivo a través de redes sociales, con alcance a audiencias fuera del campus."),
      bullet("Participación de las tres categorías de exhibición: productos innovadores, tecnologías aplicadas y emprendimientos."),
      ...space(1),

      h2("9.3 Impacto Institucional"),
      p("El evento consolidó la proyección de la FIIA como una facultad comprometida con la innovación, el emprendimiento y la transferencia del conocimiento al sector productivo. La organización exitosa de la feria en el marco del aniversario institucional reafirmó el liderazgo académico de la Facultad en el ámbito de las industrias alimentarias de la Amazonía peruana."),

      // ─── SECCIÓN 10: AGRADECIMIENTOS ──────────────────────────────
      h1("10. AGRADECIMIENTOS INSTITUCIONALES"),

      p("El Dr. Roberto Dávila Trujillo, Decano de la Facultad de Ingeniería en Industrias Alimentarias, expresó su profundo agradecimiento a todos los actores que hicieron posible el éxito de esta significativa actividad académica y productiva:"),
      ...space(1),
      bullet("A las instituciones participantes, por su confianza y apoyo en la realización de la feria."),
      bullet("A los emprendedores y estudiantes expositores, por su dedicación, creatividad y espíritu innovador."),
      bullet("A los docentes, por su orientación técnica y su permanente compromiso con la formación integral de los estudiantes."),
      bullet("Al personal administrativo, por su soporte logístico y operativo durante todas las fases del evento."),
      bullet("A la comunidad universitaria en general, por su asistencia y apoyo a los emprendedores universitarios."),
      ...space(1),
      p("El Decano destacó que actividades como la Feria de Ingeniería y Tecnología Alimentaria 2026 son fundamentales para fortalecer la formación integral de los futuros profesionales de las industrias alimentarias, al brindarles herramientas prácticas de emprendimiento y vinculación con el mercado."),

      // ─── SECCIÓN 11: CONCLUSIONES ─────────────────────────────────
      h1("11. CONCLUSIONES"),

      numbered("La Feria de Ingeniería y Tecnología Alimentaria 2026 se desarrolló con pleno éxito, cumpliendo todos los objetivos académicos, formativos y productivos planteados en su planificación."),
      numbered("La venta total de los productos expuestos es el indicador más elocuente de la calidad de los emprendimientos presentados y de la aceptación del público visitante."),
      numbered("La organización tripartita entre autoridades académicas, docentes y centro federado de estudiantes demostró ser un modelo eficiente de gestión de eventos universitarios."),
      numbered("El mecanismo de inscripción digitalizado con control de capacidad constituyó una buena práctica que debe replicarse en futuras ediciones."),
      numbered("El filtro técnico de inocuidad aplicado en la fase de pre-evento garantizó la calidad y seguridad de todos los productos puestos a disposición del público."),
      numbered("La cobertura multimedia en tiempo real amplió significativamente el alcance e impacto del evento más allá de los límites del campus universitario."),
      numbered("La feria consolidó la imagen de la FIIA como una facultad innovadora, emprendedora y comprometida con el desarrollo del sector alimentario de la Amazonía peruana."),

      // ─── SECCIÓN 12: RECOMENDACIONES ──────────────────────────────
      h1("12. RECOMENDACIONES"),

      numbered("Institucionalizar la Feria de Ingeniería y Tecnología Alimentaria como evento anual de la FIIA, ampliando progresivamente su alcance y convocatoria."),
      numbered("Incorporar un sistema de evaluación y reconocimiento de los mejores emprendimientos, con premios institucionales que incentiven la participación."),
      numbered("Explorar la vinculación con empresas del sector agroindustrial regional para que actúen como jurados, compradores potenciales y patrocinadores del evento."),
      numbered("Ampliar la difusión previa del evento a través de los medios de comunicación locales y regionales para incrementar la afluencia del público externo."),
      numbered("Diseñar un protocolo de seguimiento post-feria para los emprendimientos participantes, con asesoría en formalización, financiamiento y acceso a mercados."),
      numbered("Evaluar la posibilidad de habilitar espacios adicionales para incrementar el número de stands disponibles en futuras ediciones."),

      // ─── FIRMA Y CIERRE ───────────────────────────────────────────
      new Paragraph({ children: [new PageBreak()] }),

      ...space(2),

      new Paragraph({
        alignment: AlignmentType.CENTER,
        spacing: { before: 240, after: 80 },
        children: [new TextRun({ text: "Tingo María, junio de 2026", size: 20, font: "Arial", color: "555555" })]
      }),

      ...space(3),

      new Table({
        width: { size: 9386, type: WidthType.DXA },
        columnWidths: [4493, 400, 4493],
        rows: [
          new TableRow({
            children: [
              new TableCell({
                borders: { top: { style: BorderStyle.NONE, size: 0, color: "FFFFFF" }, bottom: { style: BorderStyle.NONE, size: 0, color: "FFFFFF" }, left: { style: BorderStyle.NONE, size: 0, color: "FFFFFF" }, right: { style: BorderStyle.NONE, size: 0, color: "FFFFFF" } },
                margins: { top: 80, bottom: 80, left: 120, right: 120 },
                children: [
                  new Paragraph({ alignment: AlignmentType.CENTER, border: { bottom: { style: BorderStyle.SINGLE, size: 4, color: VERDE, space: 2 } }, children: [new TextRun({ text: " ", size: 22, font: "Arial" })] }),
                  new Paragraph({ alignment: AlignmentType.CENTER, spacing: { before: 80 }, children: [new TextRun({ text: "Dra. Elizabeth Susana Ordoñez Gómez", bold: true, size: 20, font: "Arial" })] }),
                  new Paragraph({ alignment: AlignmentType.CENTER, children: [new TextRun({ text: "Directora General del Evento", size: 18, font: "Arial", color: "555555" })] }),
                  new Paragraph({ alignment: AlignmentType.CENTER, children: [new TextRun({ text: "FIIA – UNAS", size: 18, font: "Arial", color: "555555" })] }),
                ]
              }),
              new TableCell({
                borders: { top: { style: BorderStyle.NONE, size: 0, color: "FFFFFF" }, bottom: { style: BorderStyle.NONE, size: 0, color: "FFFFFF" }, left: { style: BorderStyle.NONE, size: 0, color: "FFFFFF" }, right: { style: BorderStyle.NONE, size: 0, color: "FFFFFF" } },
                children: [new Paragraph({ children: [new TextRun("  ")] })]
              }),
              new TableCell({
                borders: { top: { style: BorderStyle.NONE, size: 0, color: "FFFFFF" }, bottom: { style: BorderStyle.NONE, size: 0, color: "FFFFFF" }, left: { style: BorderStyle.NONE, size: 0, color: "FFFFFF" }, right: { style: BorderStyle.NONE, size: 0, color: "FFFFFF" } },
                margins: { top: 80, bottom: 80, left: 120, right: 120 },
                children: [
                  new Paragraph({ alignment: AlignmentType.CENTER, border: { bottom: { style: BorderStyle.SINGLE, size: 4, color: VERDE, space: 2 } }, children: [new TextRun({ text: " ", size: 22, font: "Arial" })] }),
                  new Paragraph({ alignment: AlignmentType.CENTER, spacing: { before: 80 }, children: [new TextRun({ text: "Dr. Roberto Dávila Trujillo", bold: true, size: 20, font: "Arial" })] }),
                  new Paragraph({ alignment: AlignmentType.CENTER, children: [new TextRun({ text: "Decano", size: 18, font: "Arial", color: "555555" })] }),
                  new Paragraph({ alignment: AlignmentType.CENTER, children: [new TextRun({ text: "Facultad de Ingeniería en Industrias Alimentarias – UNAS", size: 18, font: "Arial", color: "555555" })] }),
                ]
              }),
            ]
          })
        ]
      }),

      ...space(3),

      new Table({
        width: { size: 9386, type: WidthType.DXA },
        columnWidths: [9386],
        rows: [
          new TableRow({
            children: [
              new TableCell({
                borders,
                shading: { fill: VERDE, type: ShadingType.CLEAR },
                margins: { top: 120, bottom: 120, left: 240, right: 240 },
                children: [
                  new Paragraph({
                    alignment: AlignmentType.CENTER,
                    children: [new TextRun({ text: "Innovación  •  Tecnología  •  Nutrición  •  Futuro", bold: true, size: 22, font: "Arial", color: BLANCO })]
                  }),
                  new Paragraph({
                    alignment: AlignmentType.CENTER,
                    children: [new TextRun({ text: "FIIA – Universidad Nacional Agraria de la Selva | Tingo María, Perú", size: 18, font: "Arial", color: "CCFFCC" })]
                  })
                ]
              })
            ]
          })
        ]
      }),
    ]
  }]
});

Packer.toBuffer(doc).then(buffer => {
  fs.writeFileSync('/mnt/user-data/outputs/Informe_Feria_FIIA_2026.docx', buffer);
  console.log('Documento creado exitosamente.');
});

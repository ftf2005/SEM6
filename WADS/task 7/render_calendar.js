function loadXMLDoc(filename) {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", filename, false);
    xhttp.send();
    return xhttp.responseXML;
}

function renderCalendar(xml) {
    var svgNS = "http://www.w3.org/2000/svg";
    var svg = document.createElementNS(svgNS, "svg");
    svg.setAttribute("width", "800");
    svg.setAttribute("height", "1100");

    var rect = document.createElementNS(svgNS, "rect");
    rect.setAttribute("width", "100%");
    rect.setAttribute("height", "100%");
    rect.setAttribute("fill", "#ADD8E6");
    svg.appendChild(rect);

    var yearText = document.createElementNS(svgNS, "text");
    yearText.setAttribute("x", "400");
    yearText.setAttribute("y", "50");
    yearText.setAttribute("font-family", "Arial");
    yearText.setAttribute("font-size", "36");
    yearText.setAttribute("fill", "black");
    yearText.setAttribute("text-anchor", "middle");
    yearText.textContent = "2025";
    svg.appendChild(yearText);

    var titleText = document.createElementNS(svgNS, "text");
    titleText.setAttribute("x", "400");
    titleText.setAttribute("y", "90");
    titleText.setAttribute("font-family", "Arial");
    titleText.setAttribute("font-size", "24");
    titleText.setAttribute("fill", "black");
    titleText.setAttribute("text-anchor", "middle");
    titleText.textContent = "Yearly Calendar";
    svg.appendChild(titleText);

    var months = xml.getElementsByTagName("month");
    var positions = [
        { x: 50, y: 130 }, { x: 300, y: 130 }, { x: 550, y: 130 },
        { x: 50, y: 350 }, { x: 300, y: 350 }, { x: 550, y: 350 },
        { x: 50, y: 570 }, { x: 300, y: 570 }, { x: 550, y: 570 },
        { x: 50, y: 790 }, { x: 300, y: 790 }, { x: 550, y: 790 }
    ];

    for (var i = 0; i < months.length; i++) {
        var month = months[i];
        var monthName = month.getAttribute("name");
        var days = month.getElementsByTagName("day");

        var monthRect = document.createElementNS(svgNS, "rect");
        monthRect.setAttribute("x", positions[i].x);
        monthRect.setAttribute("y", positions[i].y);
        monthRect.setAttribute("width", "200");
        monthRect.setAttribute("height", "200");
        monthRect.setAttribute("fill", "#1E90FF");
        svg.appendChild(monthRect);

        var monthText = document.createElementNS(svgNS, "text");
        monthText.setAttribute("x", positions[i].x + 100);
        monthText.setAttribute("y", positions[i].y + 30);
        monthText.setAttribute("font-family", "Arial");
        monthText.setAttribute("font-size", "18");
        monthText.setAttribute("fill", "white");
        monthText.setAttribute("text-anchor", "middle");
        monthText.textContent = monthName;
        svg.appendChild(monthText);

        var dayLabels = ["S", "M", "T", "W", "T", "F", "S"];
        for (var j = 0; j < dayLabels.length; j++) {
            var dayLabel = document.createElementNS(svgNS, "text");
            dayLabel.setAttribute("x", positions[i].x + 30 + j * 30);
            dayLabel.setAttribute("y", positions[i].y + 60);
            dayLabel.setAttribute("font-family", "Arial");
            dayLabel.setAttribute("font-size", "14");
            dayLabel.setAttribute("fill", "white");
            dayLabel.textContent = dayLabels[j];
            svg.appendChild(dayLabel);
        }

        for (var j = 0; j < days.length; j++) {
            var day = days[j].textContent;
            var dayText = document.createElementNS(svgNS, "text");
            dayText.setAttribute("x", positions[i].x + 30 + (j % 7) * 30);
            dayText.setAttribute("y", positions[i].y + 90 + Math.floor(j / 7) * 20);
            dayText.setAttribute("font-family", "Arial");
            dayText.setAttribute("font-size", "14");
            dayText.setAttribute("fill", "white");
            dayText.textContent = day;
            svg.appendChild(dayText);
        }
    }

    var anyYearButton = document.createElementNS(svgNS, "rect");
    anyYearButton.setAttribute("x", "300");
    anyYearButton.setAttribute("y", "950");
    anyYearButton.setAttribute("width", "200");
    anyYearButton.setAttribute("height", "50");
    anyYearButton.setAttribute("fill", "#1E90FF");
    svg.appendChild(anyYearButton);

    var anyYearText = document.createElementNS(svgNS, "text");
    anyYearText.setAttribute("x", "400");
    anyYearText.setAttribute("y", "985");
    anyYearText.setAttribute("font-family", "Arial");
    anyYearText.setAttribute("font-size", "18");
    anyYearText.setAttribute("fill", "white");
    anyYearText.setAttribute("text-anchor", "middle");
    anyYearText.textContent = "ANY YEAR";
    svg.appendChild(anyYearText);

    document.body.appendChild(svg);
}

var xml = loadXMLDoc("calendar_2025.xml");
renderCalendar(xml);

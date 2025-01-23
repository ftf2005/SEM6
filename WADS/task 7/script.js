document.addEventListener("DOMContentLoaded", function() {
    const xmlData = `
    <calendar year="2025">
        <month name="January" days="31" startDay="2"/>
        <month name="February" days="28" startDay="5"/>
        <month name="March" days="31" startDay="5"/>
        <month name="April" days="30" startDay="1"/>
        <month name="May" days="31" startDay="3"/>
        <month name="June" days="30" startDay="6"/>
        <month name="July" days="31" startDay="1"/>
        <month name="August" days="31" startDay="4"/>
        <month name="September" days="30" startDay="0"/>
        <month name="October" days="31" startDay="3"/>
        <month name="November" days="30" startDay="6"/>
        <month name="December" days="31" startDay="2"/>
    </calendar>`;

    const parser = new DOMParser();
    const xml = parser.parseFromString(xmlData, "application/xml");
    const months = xml.getElementsByTagName("month");
    const daysOfWeek = ["S", "M", "T", "W", "T", "F", "S"];
    const monthsContainer = document.querySelector(".months");

    Array.from(months).forEach((month, index) => {
        const monthName = month.getAttribute("name");
        const totalDays = parseInt(month.getAttribute("days"), 10);
        const startDay = parseInt(month.getAttribute("startDay"), 10);

        const monthDiv = document.createElement("div");
        monthDiv.classList.add("month");

        const monthHeader = document.createElement("h3");
        monthHeader.textContent = monthName;
        monthDiv.appendChild(monthHeader);

        const daysHeader = document.createElement("div");
        daysHeader.classList.add("days-header");
        daysOfWeek.forEach(day => {
            const dayHeader = document.createElement("span");
            dayHeader.classList.add("day");
            dayHeader.textContent = day;
            daysHeader.appendChild(dayHeader);
        });
        monthDiv.appendChild(daysHeader);

        const daysContainer = document.createElement("div");
        daysContainer.classList.add("days-container");
        for (let i = 0; i < startDay; i++) {
            const emptyDay = document.createElement("span");
            emptyDay.classList.add("day");
            daysContainer.appendChild(emptyDay);
        }
        for (let i = 1; i <= totalDays; i++) {
            const dayDiv = document.createElement("span");
            dayDiv.classList.add("day");
            dayDiv.textContent = i;
            daysContainer.appendChild(dayDiv);
        }
        monthDiv.appendChild(daysContainer);

        monthsContainer.appendChild(monthDiv);
    });
});

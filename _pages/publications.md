---
layout: page
permalink: /publications/
title: Publications
description: "* indicates equal contribution."
years: [2024, 2023, 2022, 2021, 2020, 2019]
nav: true
---
<!-- _pages/publications.md -->
<div class="publications">

Please see <a href="https://scholar.google.com/citations?user=YZnEeJUAAAAJ"> Google Scholar</a> for a complete and up-to-date list of publications.

{%- for y in page.years %}
  <h2 class="year">{{y}}</h2>
  {% bibliography -f papers -q @*[year={{y}}]* %}
{% endfor %}

</div>

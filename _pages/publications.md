---
layout: page
permalink: /publications/
title: Publications
description: "* indicates equal contribution."
years: [2023, 2022, 2021, 2020, 2019]
nav: true
---
<!-- _pages/publications.md -->
<div class="publications">

Also at <a href="https://scholar.google.com/citations?user=YZnEeJUAAAAJ"> Google Scholar</a>.

{%- for y in page.years %}
  <h2 class="year">{{y}}</h2>
  {% bibliography -f papers -q @*[year={{y}}]* %}
{% endfor %}

</div>

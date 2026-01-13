% ---------------------------------------------------------------------
% EG author guidelines plus sample file for EG publication using LaTeX2e input
% D.Fellner, v2.04, Dec 14, 2023

\usepackage{tikz}
\usepackage{amssymb}
\usepackage{graphicx}
\usepackage{booktabs}
\usepackage{hyperref}

\title[From Hairballs to Hypotheses]%
      {From Hairballs to Hypotheses: A Survey of AI-Assisted Visual Analytics in the Life Sciencess}

% for anonymous conference submission please enter your SUBMISSION ID
% instead of the author's name (and leave the affiliation blank) !!
% for final version: please provide your *own* ORCID in the brackets following \orcid; see https://orcid.org/ for more details.
\author[Chukhman et al.]
{\parbox{\textwidth}{\centering
Morris Chukhman$^{1,2}$,
Amira Kefi$^{1}$,
Nicole M. Chukhman$^{3}$,
Silvio Rizzi$^{1,4}$,
Vinayakumar Chalil Karintha$^{5}$\,
and Angus Forbes$^{6}$\\[1ex]
{\small
$^{1}$University of Illinois at Chicago, Chicago, IL, USA\\
$^{2}$St. Luke's University Health Network, Stroudsburg, PA, USA \\
$^{3}$University of Wisconsin - Madison, Madison, WI, USA \\
$^{4}$Argonne National Laboratory, Lemont, IL, USA \\
$^{5}$UST, Thiruvananthapuram, Kerala, India \\
$^{6}$NVIDIA, Santa Clara, CA, USA \\
}
}
}
% ------------------------------------------------------------------------

% if the Editors-in-Chief have given you the data, you may uncomment
% the following five lines and insert it here
%
% \volume{36}   % the volume in which the issue will be published;
% \issue{1}     % the issue number of the publication
% \pStartPage{1}      % set starting page


%-------------------------------------------------------------------------
\begin{document}

% uncomment for using teaser
% \teaser{
%  \includegraphics[width=0.9\linewidth]{eg_new}
%  \centering
%   \caption{New EG Logo}
% \label{fig:teaser}
%}

\maketitle
%-------------------------------------------------------------------------
\begin{abstract}
Visual analytics in the life sciences increasingly confronts “hairballs”: dense, heterogeneous, and multiscale data whose visual clutter and interaction overhead prevent analysts from forming, testing, and communicating hypotheses. In this State-of-the-Art Report, we synthesize research at the intersection of visualization modality and AI-assisted interaction for life science analytics. We organize the literature using a two-dimensional conceptual model that characterizes systems along two orthogonal axes: the visualization environment, ranging from conventional 2D desktop interfaces to large collaborative displays, immersive virtual and augmented reality, and hybrid cross-device ecosystems; and the mode of AI assistance, including algorithmic, adaptive, conversational, and immersive interaction support. To ground this synthesis in analytic practice, we consolidate prior task taxonomies into five task categories that capture common intents in life science analysis: navigation and multiscale orientation, comparison and differentiation, selection and precision interaction, sensemaking and hypothesis development, and coordination and collaborative reasoning. Using this framework, we summarize representative systems and mechanisms, discuss recurring evaluation practices and limitations, and highlight persistent design pressures related to scalability, representational fidelity, and auditability across hypothesis-driven workflows.

% ---------------------------------------------------------------
\section*{Keywords}
Biological Visualization, Network Visualization, Artificial Intelligence, Large Language Models, Immersive Analytics, Human–AI Collaboration, Design Studies, Cognitive Principles.

% ---------------------------------------------------------------
%-------------------------------------------------------------------------
%  ACM CCS 2012
%  (see https://www.acm.org/publications/class-2012)
%  The tool at https://dl.acm.org/ccs can be used to generate CCS codes.
%-------------------------------------------------------------------------

\begin{CCSXML}
<ccs2012>
  <concept>
    <concept_id>10003120.10003121.10011748</concept_id>
    <concept_desc>Human-centered computing~Visualization</concept_desc>
    <concept_significance>500</concept_significance>
  </concept>
  <concept>
    <concept_id>10003120.10003121.10003125.10010597</concept_id>
    <concept_desc>Human-centered computing~Visual analytics</concept_desc>
    <concept_significance>500</concept_significance>
  </concept>
  <concept>
    <concept_id>10003120.10003121.10003129</concept_id>
    <concept_desc>Human-centered computing~Interactive systems and tools</concept_desc>
    <concept_significance>300</concept_significance>
  </concept>
  <concept>
    <concept_id>10003120.10003121.10003124</concept_id>
    <concept_desc>Human-centered computing~Human computer interaction (HCI)</concept_desc>
    <concept_significance>200</concept_significance>
  </concept>
</ccs2012>
\end{CCSXML}

\ccsdesc[500]{Human-centered computing~Visualization}
\ccsdesc[500]{Human-centered computing~Visual analytics}
\ccsdesc[300]{Human-centered computing~Interactive systems and tools}
\ccsdesc[200]{Human-centered computing~Human computer interaction (HCI)}

\printccsdesc   
\end{abstract}  

%-------------------------------------------------------------------------
\section{Introduction}
% \textit{Introduce the context of life-science data (complex, high-dimensional “hairballs”), the challenges for visualization, and the rise of AI assistance. Define the goal and scope of the STAR. Provide an overview of the two-dimensional conceptual model (AI assistance modes crossed with visualization modalities) and the structure of the report.}
% \textit{(Remove this drafting note before submission.)}

Visual analytics in the life sciences has grown quickly over the last two decades because biological data are now larger, more heterogeneous, and more dynamic. Many workflows combine multiple data types in one analysis: \emph{-omics} profiles, spatially resolved measurements in tissue (spatial profiling / spatial transcriptomics), and high-resolution imaging that supports tasks like connectome reconstruction and circuit analysis \cite{Crosetto2015SpatialTranscriptomics,Moffitt2022SpatialProfiling,Beyer2022ConnectomicsSTAR}. These data often include dense relationships between genes, cells, regions, or neurons, that quickly become hard to read and hard to explore. This is the ``hairball'' problem in a broad sense: the display becomes cluttered and interaction breaks down just when analysts need overview, selection, and comparison. Systems therefore increasingly move beyond static depictions toward interactive environments that help users form and test hypotheses.

At the same time, the visualization toolkit itself has expanded. Desktop 2D tools remain the default, but many life-science workflows now also use large high-resolution displays and immersive platforms such as VR/AR and CAVE-like rooms. In parallel, visual analytics systems increasingly incorporate AI assistance, from algorithmic methods (e.g., clustering and dimensionality reduction) to adaptive interfaces and conversational interaction, to reduce manual burden and to support iterative reasoning. Immersive analytics occupies a particularly nuanced position in this space, since three-dimensional environments can both support spatial understanding and complicate reasoning when data are large and highly relational.



This State-of-the-Art Report (STAR) introduces a two-dimensional conceptual model that crosses \emph{AI Assistance Modes} with \emph{Visualization Modalities}. We distinguish four modes of AI assistance: \emph{algorithmic}, \emph{adaptive}, \emph{conversational}, and \emph{immersive} (i.e., assistance that leverages spatial/embodied interaction rather than simply using an immersive display); and five visualization modalities: \emph{2D desktop}, \emph{large displays}, \emph{virtual reality (VR)}, \emph{augmented reality (AR)}, and \emph{CAVE} environments. Using this matrix as an organizing framework, the STAR surveys how different combinations support life-science visual analytics, identifies recurring task and interaction taxonomies, and reviews evaluation methods, intelligent assistance mechanisms, and open research challenges \cite{Ehlers2025,Joos2025VisNetIA}.

Our goal is to provide a roadmap similar to Filipov et al.'s meta-survey of network visualization \cite{Filipov2023Roadmap}, but focused specifically on the intersection of AI assistance and visualization modality. The remainder of this STAR first establishes shared task foundations and a unified taxonomy for life-science visual analytics, then surveys the AI--modality matrix across desktop, large-display, and immersive settings, and finally synthesizes evaluation practices and open challenges that arise when moving from hairball depiction toward hypothesis-driven analysis.

\subsection{Scope and Definitions}
\label{sec:scope-defs}

Our work centers on life-science visual analytics problems where data items are connected by many relationships that can quickly become hard to see or explore. Particular attention is given to graphs and networks that appear across biology, such as protein–protein interaction networks, signaling pathways, and brain connectomes. We also consider cases where networks are not provided directly but are instead constructed from other data. For example, spatial-omics, tissue imaging, and neuronal tracing often yield neighborhood links or connectivity models that must be studied together with spatial and anatomical context. These different relationship types are described in more detail in Section \ref{sec:data-relationship-types}. 

Within this scope, we define AI assistance modes as follows:
\begin{itemize}
    \item \textbf{Algorithmic assistance} refers to automated computational analysis integrated into the visualization pipeline, such as graph mining, clustering, dimensionality reduction, or machine learning--based preprocessing.

    \item \textbf{Adaptive assistance} denotes systems that dynamically tailor visualizations or interactions based on user behavior, task context, or data characteristics.

    \item \textbf{Conversational assistance} encompasses natural language or dialogue-based interfaces that allow users to steer visual analysis through queries, explanations, or recommendations.

    \item \textbf{Immersive assistance} goes beyond merely displaying data in immersive environments and instead leverages immersion itself, through spatialization, embodiment, or multisensory cues, as an active mechanism for insight.
\end{itemize}

Visualization modalities are defined following established immersive analytics literature \cite{Fonnet2019ImmersiveAnalytics,Milgram1994MR} and include traditional 2D desktop setups; large displays such as powerwalls and tiled displays that afford high resolution and physical navigation; VR environments offering full immersion via head-mounted displays; AR systems that overlay visual information onto the physical world; and CAVE-like multi-screen immersive rooms supporting co-located collaboration. Each modality introduces distinct affordances and constraints. For example, VR and AR can enhance spatial understanding for certain analytical tasks \cite{Sedlmair2014GoodBadUgly,Ware2008Graphs3D}, while large displays support collaborative analysis by making many data items visible simultaneously.

Table \ref{table:taxonomy-matrix} summarizes our 4×5 matrix of AI assistance modes and visualization modalities, with representative research questions for each cell (e.g., How can conversational agents assist network exploration in VR? or How do adaptive techniques differ between 2D and AR for graph visualization?). This matrix serves as the structural backbone of the STAR. Our survey reveals that some combinations, such as algorithmic assistance in 2D desktop environments, are well studied, whereas others, such as conversational support in CAVE systems or adaptive AR analytics, remain sparsely explored. We highlight these imbalances throughout the report as indicators of open research gaps.

We do not attempt to survey the full breadth of bioimage analysis or computational biology. Instead, we prioritize systems and studies where interactive visualization is used to support analytical tasks over dense relationships, derived structures, or multiscale biological context. The scope of this review is more precisely defined in Section \ref{sec:scope-exclusions}.

% Conceptual Model: AI Assistance × Visualization Modality

\begin{table}[t]
\centering
\small
\resizebox{\columnwidth}{!}{
\begin{tabular}{l|c|c|c|c}
\textbf{Modality} & \textbf{Algorithmic} & \textbf{Adaptive} & \textbf{Conversational} & \textbf{Immersive} \\
\hline
Desktop (2D) & \checkmark & \checkmark & \checkmark & \(\sim\) \\
Large Display & \(\sim\) & \(\sim\) & \(\sim\) & \(\sim\) \\
VR & \checkmark & \(\sim\) & \(\sim\) & \checkmark \\
AR & \checkmark & \(\sim\) & — & \checkmark \\
CAVE/Hybrid & \(\sim\) & — & — & \(\sim\) \\
\end{tabular}
}
\caption{Visualization modalities can host any AI assistance mode; immersive-AI refers to AI techniques that operate specifically within immersive environments.
\checkmark = Supported (over 10 papers); \(\sim\) = Emerging (1-10 papers); 
— = Unsupported (no papers)}
\label{table:taxonomy-matrix}
\end{table}


\subsection{Methodology}

To collect the relevant literature, we conducted systematic searches across visualization, Human-Computer Interaction (HCI), and AI venues, informed by prior surveys and bibliographies \cite{Ehlers2025,Joos2025VisNetIA,Fonnet2019ImmersiveAnalytics}. In particular, we leveraged Joos et al.’s immersive network analysis survey (138 papers), Ehlers et al.’s survey of biological network visualization (83 papers), and Fonnet and Prié’s immersive analytics survey (177 works). We complemented these sources with targeted searches for combinations such as adaptive graph visualization, user modeling, and conversational visual analytics with large language models. We also reviewed recent STAR reports to ensure comprehensive coverage.

Publications were included if they addressed both visualization and AI or intelligent interaction aspects, and if they fell within the defined modality scope. Each major section of the STAR maps the surveyed literature onto our conceptual model and concludes with a synthesis of key trends, limitations, and opportunities for future work. Detailed publication research procedures are discussed in Appendix \ref{app:methodology}.

\begin{figure}[ht]
    \centering
    \includegraphics[width=0.5\textwidth]{grouped_barchart3.png}
    \caption{Distribution of relevant papers across AI Assistance Modes and Visualization Modalities. The chart highlights the dominance of Desktop interfaces for Algorithmic and Adaptive tasks, while Immersive-AI is heavily concentrated in VR environments.}
    \label{fig:paper_distribution}
\end{figure}

\section{Background and Scope}
% \textit{Establish foundational definitions and the survey’s scope.}

% \section{Background and Taxonomies}
\label{sec:background-taxonomies}

% Before examining specific combinations of AI assistance modes and visualization modalities, we first summarize the foundational task, interaction, and system taxonomies that underpin much of the literature surveyed in this report. These frameworks provide a common vocabulary for comparing systems across domains, modalities, and levels of intelligence, and they inform how we interpret the role of AI assistance throughout the visual analytics pipeline.
This section establishes the conceptual scope and definitions used throughout this State-of-the-Art Report. We define the types of data and relationships addressed, introduce the two dimensions of our survey matrix: visualization modalities and AI assistance modes, and clarify the boundaries of the literature considered. These definitions provide the context necessary for interpreting the task, interaction, and evaluation frameworks discussed in subsequent sections.

\subsection{Data and Relationship Types in Life-Science Visual Analytics}
%\textit{ Describe the types of biological data (networks, trajectories, spatial data, etc.) and relationships addressed by visual analytics in life sciences.}

% \subsection{Data and Relationship Types in Life-Science Visual Analytics}
\label{sec:data-relationship-types}

Life-science visual analytics encompasses a wide range of data types and relational structures. A central theme across many domains is the analysis of relationships, whether explicitly encoded as graphs or implicitly derived from spatial, temporal, or multivariate data. Common examples of explicit relational data include biological networks such as protein--protein interaction networks, gene regulatory networks, metabolic pathways, and connectomes, which may represent physical interactions, functional associations, or inferred statistical dependencies.

In addition to explicit networks, life-science analytics frequently involves spatially and temporally grounded data that give rise to relational structure. Examples include neuronal morphologies reconstructed from imaging, spatial organization of cells in tissue, trajectories of cells or molecules over time, and longitudinal clinical measurements. In these settings, relationships are often derived implicitly through spatial adjacency, neighborhood graphs, lineage trees, or similarity measures, rather than provided explicitly as node--link structures.

These heterogeneous data types commonly coexist within a single analytical workflow. For example, molecular interaction networks may be analyzed alongside genomic signals, experimental metadata, spatial context, or image-derived structures. As a result, visual analytics systems in the life sciences must support reasoning across multiple relationship types, scales, and representations. Throughout this report, we use biological networks as a recurring and illustrative example of relational complexity, while recognizing that many of the principles discussed generalize to other forms of relational and multivariate data encountered in contemporary life-science analytics.



\subsection{Visualization Modalities (Matrix Dimension~1)}
%\textit{ Define the visualization environments considered (2D desktop, large displays, VR, AR, CAVE) and their differing affordances.}
 % \subsection{Visualization Modalities}
\label{sec:visualization-modalities-intro}

The first dimension of our conceptual model distinguishes visualization modalities [\ref{sec:visualization-modalities}], defined by the physical and technological environment in which visual analytics takes place. We consider five primary modalities commonly addressed in the visualization literature: traditional 2D desktop environments [\ref{sec:desktop-2d}], large displays (including powerwalls and tiled displays) [\ref{sec:large-displays}], virtual reality (VR) environments, augmented reality (AR) systems, and CAVE-like multi-screen immersive rooms[\ref{sec:immersive-environments}].

Each modality affords different perceptual, cognitive, and collaborative capabilities. Desktop environments emphasize precision, familiarity, and integration with computational workflows. Large displays enable shared viewing, physical navigation, and collaborative sensemaking. VR environments support stereoscopic depth, embodied navigation, and spatial immersion. AR systems overlay analytical content onto the physical world, enabling contextualized analysis, while CAVE environments combine large-scale immersion with co-located collaboration. We adopt standard definitions of these modalities from immersive analytics and visualization research, and analyze how their differing affordances shape analytic workflows in later sections.

\subsection{AI Assistance Modes (Matrix Dimension~2)}
%\textit{ Define the modes of AI assistance (algorithmic, adaptive, conversational, immersive-AI) that augment visual analytics workflows.}
 % \subsection{AI Assistance Modes}
\label{sec:ai-assistance-modes}

The second dimension of our survey matrix characterizes how AI assistance augments visual analytics systems. As defined in Section \ref{sec:scope-defs}, we distinguish four broad modes of assistance: algorithmic, adaptive, conversational, and immersive. Algorithmic assistance is precomputed and primarily operates on data and structure, providing computational leverage through techniques such as clustering, dimensionality reduction, graph mining, or learned models. Adaptive assistance focuses on the user and task context, adjusting visual encodings or interactions in response to observed behavior or inferred intent, in real-time. Conversational assistance shifts interaction toward natural language, enabling users to express analytical goals through queries, explanations, or dialogue. Immersive assistance differs from the other modes by treating spatialization, embodiment, and multisensory interaction not merely as interface features, but as integral components of the analytical process itself. These modes are not mutually exclusive, and many systems combine multiple forms of assistance. Throughout this STAR, we use this classification to analyze how different AI capabilities interact with visualization modalities, and how these combinations shape task support, usability, and analytic outcomes.

\subsection{Task Foundations for Life-Science Visual Analytics}
%\textit{ Introduce prior task taxonomies from network visualization, immersive analytics, etc., that underpin the unified task framework in this STAR.}
 % \subsection{Task Foundations for Life-Science Visual Analytics}
\label{sec:task-foundations-into}

Visual analytics research is grounded in a rich body of task and interaction taxonomies developed for graph visualization, immersive analytics, and exploratory analysis. These frameworks provide a basis for describing analytical intent, interaction strategies, and evaluation methodologies across diverse systems. Rather than introducing new task definitions, this STAR builds upon established taxonomies to compare how different AI assistance modes and visualization modalities support core analytical activities. A detailed discussion of these task foundations is provided in Section~\ref{sec:task-foundations}.

\subsection{Scope and Exclusions}
% \textit{ Clearly state what is included (biological visual analytics with AI assistance) and excluded (purely manual vis, non-analytic visuals, non-bio contexts) from this survey.}
% \subsection{Scope and Exclusions}
\label{sec:scope-exclusions}

This report focuses on visual analytics systems that combine biological data analysis with some form of AI assistance across the visualization modalities defined above. We include systems that integrate computational analysis, adaptive interaction, conversational interfaces, or immersive reasoning into visual analytics workflows. The primary application focus is on life-science domains, particularly those involving complex relational or spatial data.

We exclude purely manual visualization systems that do not incorporate AI-assisted components, as well as visualization approaches intended solely for presentation or artistic purposes rather than analysis. While some concepts discussed may generalize beyond biology, systems developed exclusively for non-biological domains are considered only insofar as they inform transferable design principles.

\section{Unified Task Taxonomy}
% \textit{ Present the new integrated task taxonomy for AI-assisted visual analytics in life sciences.}
% \section{Task and Interaction Foundations}
\label{sec:task-foundations}

This section reviews established task and interaction frameworks that underpin the systems surveyed in this report. These foundations provide a shared vocabulary for analyzing how AI assistance and visualization modality influence analytical workflows, user interaction, and evaluation.


\subsection{Rationale: Why Existing Visualization Taxonomies Are No Longer Enough}
% \textit{ Explain three reasons motivating a new taxonomy (e.g., active AI agents, multiscale bio data, immersive modality challenges).}

% \subsection{Rationale: Why Existing Visualization Taxonomies Are No Longer Enough}
\label{sec:taxonomy-rationale}

Task taxonomies have played a central role in structuring visualization research, guiding both system design and evaluation. In graph visualization, influential taxonomies such as those proposed by Lee et al.\ categorize tasks according to graph objects (nodes, edges, paths, groups) and analytical goals, including topology-based, attribute-based, and overview tasks~\cite{Lee2006TaskTaxonomy}. More general visual analytics frameworks, such as Brehmer and Munzner’s multi-level typology, organize tasks along the dimensions of \emph{why} (user intent), \emph{how} (interaction), and \emph{what} (data target), providing a flexible lens for analyzing interaction across visualization systems~\cite{Brehmer2013WhyHowWhat,Munzner2014VisualizationAnalysis}. These frameworks have proven highly effective for characterizing analysis in traditional, largely manual visualization settings.

However, recent developments in both data characteristics and analytical systems challenge the sufficiency of existing task taxonomies when applied to contemporary life-science visual analytics. First, biological data has grown not only in scale but also in heterogeneity and dynamism. Ehlers et al.\ observe that biological network visualization increasingly involves multiscale data, heterogeneous relationships, and evolving experimental contexts, placing demands on analytical workflows that extend beyond the static task formulations assumed by many earlier taxonomies~\cite{Ehlers2025}. While domain-specific task adaptations exist, these typically extend general graph tasks rather than reconceptualizing how tasks unfold in the presence of automated analysis or intelligent guidance.

Second, immersive analytics introduces new task dimensions that are not fully captured by traditional taxonomies. Fonnet and Prié highlight that immersive systems reshape analytical activity through spatialization, embodiment, and collaboration, affecting not only how tasks are performed but also which tasks become feasible or salient~\cite{Fonnet2019ImmersiveAnalytics}. Tasks related to spatial understanding, navigation, and embodied comparison emerge alongside classical graph analysis tasks, blurring the boundary between interaction mechanics and analytical intent. As immersive environments increasingly support collaborative and multisensory analysis, task frameworks that abstract away modality-specific affordances become insufficient for meaningful comparison.

Third, and most critically, the increasing presence of AI assistance alters the locus of analytical agency. Existing taxonomies largely assume that users explicitly initiate and control analytical operations, with computational methods serving as passive tools. In contrast, AI-assisted systems may proactively suggest views, detect patterns, adapt representations, or engage in dialogue with the user. Filipov et al.\ identify the integration of machine learning for pattern mining and recommendation as a key open challenge in network visualization, noting that such capabilities fundamentally change how analysts interact with and reason about data~\cite{Filipov2023Roadmap}. Under these conditions, tasks can no longer be described solely in terms of user-driven actions; they must also account for system-initiated analysis, adaptive behavior, and mixed-initiative workflows.

Together, these developments motivate the need for a unified task taxonomy that explicitly accounts for three interacting dimensions: the analytical task itself, the visualization modality in which it is performed, and the mode of AI assistance that mediates the interaction. Rather than replacing existing taxonomies, such a framework builds upon them to enable systematic comparison across AI-assisted visual analytics systems operating in diverse modalities. In the following sections, we introduce this unified taxonomy and use it to structure our survey of AI-assisted visual analytics in the life sciences.

\subsection{The Unified Task Taxonomy}
\label{sec:unified-task-taxonomy}

To address the limitations identified in Section~\ref{sec:taxonomy-rationale}, we propose a unified task taxonomy for AI-assisted visual analytics in the life sciences. The taxonomy provides a structured lens for comparing how analytical tasks are supported and transformed across visualization modalities and AI assistance.

We organize the design space along three axes: (1) \emph{what} analytical task is being performed, (2) \emph{where} the task is enacted in terms of visualization modality, and (3) \emph{how} the task is mediated by AI assistance. These axes reflect increasing task complexity in biological data, modality-dependent affordances (e.g., large displays and immersive environments), and AI’s growing role as an active analytical agent.

The first dimension, \emph{analytical task}, builds on established task taxonomies in graph visualization and visual analytics. Rather than enumerating fine-grained operations, we define generalized task categories that capture recurring intent in biological workflows (e.g., exploration, comparison, abstraction, and hypothesis refinement). The categories are abstract enough to cover both manual and AI-mediated variants while remaining grounded in prior frameworks.

The second dimension, \emph{visualization modality}, encodes the environment in which a task is performed (2D desktop systems, large displays, immersive VR, AR, and CAVE-like setups). Treating modality as a first-class axis accounts for how perceptual, spatial, and collaborative affordances shape task execution and enables direct comparisons of the same task across environments.

The third dimension, \emph{AI assistance mode}, characterizes how computational intelligence intervenes in analysis. We distinguish algorithmic, adaptive, conversational, and immersive assistance (Section~\ref{sec:ai-assistance-modes}) and use this axis to capture the degree and form of system initiative: tasks may be user-driven, system-suggested, adaptively guided, or jointly negotiated through dialogue, reflecting mixed-initiative workflows.

Together, these dimensions enable systematic categorization of the STAR literature: each system can be positioned by the tasks it supports, the modality in which those tasks occur, and the assistance mode it employs. This structure helps surface patterns and gaps (e.g., task categories that are well supported algorithmically in 2D tools but underexplored in immersive or conversational settings).

In Section~\ref{sec:task-categories}, we instantiate the framework with generalized task categories that provide the organizational backbone for the remainder of the paper.

\subsection{Task Categories in the Unified Taxonomy}
% \textit{List and define the generalized task categories that span life-science visual analytics.}
\label{sec:task-categories}

This subsection defines the generalized task categories that constitute the unified taxonomy for AI-assisted visual analytics in the life sciences. The categories capture recurring analytical intent across biological workflows while remaining abstract enough to span visualization modalities and modes of AI assistance.

Prior task taxonomies in graph visualization and visual analytics characterize intent from object-centric (Lee et al.~\cite{Lee2006TaskTaxonomy}), intent-centric (Munzner~\cite{Munzner2014VisualizationAnalysis}), or technology-centric (Filipov et al.~\cite{Filipov2023Roadmap}) perspectives. We synthesize recurring intents across these frameworks into modality-aware and AI-aware task classes suited to mixed-initiative visual analytics.

The unified taxonomy comprises five task categories:
\begin{itemize}
    \item \emph{Navigation and Multiscale Orientation}
    \item \emph{Comparison and Differentiation}
    \item \emph{Selection, Filtering, and Precision Interaction}
    \item \emph{Sensemaking and Hypothesis Development}
    \item \emph{Coordination and Collaborative Reasoning}
\end{itemize}
Together, these categories span activities from individual exploration and precise interaction to collective reasoning and hypothesis refinement.

Each category may be instantiated differently depending on visualization modality and AI assistance mode. Rather than enumerating representative systems in a standalone section, we integrate examples throughout the task-driven discussion, using modality and assistance mode to contextualize design trade-offs and open challenges across mixed-initiative workflows.

\subsubsection{Navigation and Multiscale Orientation}
\label{sec:automated-view-switching}
% \textit{E.g., zooming across scales, traversing networks or anatomy, viewpoint management, note why AI (e.g., guided navigation) is essential for deep 3D or multiscale navigation.}

Navigation and multiscale orientation encompass tasks in which analysts traverse hierarchical or spatial structures while maintaining context across levels of abstraction (e.g., cohort-to-individual transitions). In immersive systems, such transitions are often manual, requiring users to switch between exocentric (overview) and egocentric (inside-out) views and to manage viewpoint, scale, and locomotion; this can introduce substantial cognitive and physical overhead in dense biomedical environments.

Empirical results highlight that frames of reference can differentially support analytic intent. Ng et al.\ report that cohort-level tasks are completed more efficiently in exocentric views than egocentric views in VR, while performance in egocentric views is strongly coupled to interaction usability~\cite{Ng2024ExoEgo}. This suggests that egocentric immersion can be valuable for focused inspection and embodied spatial memory, but only when navigation and interaction remain manageable.

These findings motivate intent-aware, AI-mediated multiscale control: instead of requiring analysts to manually manage scale and frame of reference, an assistant can infer analytic scope from interaction signals (e.g., selection, filtering, query breadth) and trigger appropriate viewpoint or scale transitions. This reframes navigation as a semantic problem tied to analytic intent, where automated view switching aims to reduce disorientation and preserve cognitive continuity across abstraction levels. Mechanisms for intent inference and real-time viewpoint control are discussed further in Section~\ref{sec:immersive-ai}.

\subsubsection{Selection, Filtering, and Precision Interaction}
\label{sec:selection-filtering-precision}
% \textit{E.g., selecting subsets (genes, cells), filtering by attributes or scores, decluttering dense visuals, note how conversational queries or gaze-driven selection can assist.}

Selection, filtering, and precision interaction capture tasks in which analysts specify subsets and constraints (e.g., selecting a cluster, filtering cohorts, thresholding edges, isolating regions of interest) to reduce analytic complexity and express intent. These operations are central to iterative analysis, not ancillary interactions.

This category also exposes modality-dependent constraints. Desktop environments support stable pointing and parameter entry, whereas immersive environments frequently rely on ray casting and mid-air manipulation that can be less stable for dense targets and more fatiguing. As a result, immersive systems often benefit from assistance mechanisms that translate imprecise input into reliable analytic operations via constraints, snapping, and disambiguation. One general strategy is intent-aware selection that fuses signals such as gaze, proximity, dwell time, and recent queries to infer the intended target and stabilize interaction.

Representative systems instantiate these principles in different ways. Dai et al.\ present Magic Portals, which preserve context while enabling fine-grained interaction with distant targets by bringing a focus region into comfortable reach~\cite{Dai2025MagicPortals}. Mishra et al.\ show that constrained interaction can make immersive molecular manipulation productive when actions are restricted to physically meaningful states and can be reused downstream~\cite{Mishra2024DockingVR}. Filtering further serves as a primary decluttering mechanism, often coupled with attention guidance in immersive settings; Doerr et al.\ analyze highlighting encodings for situated brushing and linking, noting trade-offs between findability and clutter as selection sizes grow~\cite{Doerr2024SituatedHighlighting}. In mixed-initiative systems, this category often becomes the interface between human hypothesis and computational support: users express constraints, and AI helps execute them precisely and transparently.

\subsubsection{Comparison and Differentiation}
\label{sec:comparison-differentiation}
% \textit{E.g., comparing experimental conditions or timepoints, aligning datasets, visualizing changes, note AI help like pattern discovery or narrative description, and immersive benefits (spatial overlays).}

Comparison and differentiation include contrasting conditions or timepoints, comparing cohorts, aligning representations (e.g., embeddings), and identifying outliers or structural shifts. These tasks depend on stable correspondence so that perceived differences reflect the data rather than interaction artifacts.

Immersive environments commonly support comparison through (at least) two complementary strategies. First, they can externalize similarity into spatial proximity, enabling exploratory differentiation via navigation in a similarity landscape (e.g., VROOM)~\cite{Lau2022}. Second, they can emphasize coordinated multiview comparison with synchronized interactions that preserve alignment across subjects or coordinate systems (e.g., NeuroCave)~\cite{Keiriz2017NeuroCave}. The former supports intuitive exploration and spatial memory, while the latter supports structured verification by minimizing contextual drift.

As AI assistance becomes more common, comparison tasks are also a natural substrate for pattern discovery and summarization: algorithms can propose salient contrasts, rank candidate differences, or generate brief descriptions that users can validate through aligned views and explicit filtering.

\subsubsection{Sensemaking and Hypothesis Development}
\label{sec:sensemaking-hypothesis}
% \textit{Sensemaking and hypothesis development tasks encompass the construction, refinement, and validation of mental models, including data contextualization, annotation, explanation, and the generation of biological hypotheses.}

Sensemaking and hypothesis development describe the interpretive work of constructing mental models, contextualizing observations, and iteratively refining questions into testable hypotheses. These tasks commonly progress from overview to isolating candidate structure, contextualizing with metadata or domain knowledge, externalizing interpretations (e.g., annotation), and testing alternatives via comparison, filtering, and follow-up queries.

Mixed-initiative assistance is most visible here: AI can summarize patterns, suggest candidate relationships, retrieve contextual information, or recommend alternative views and parameters. However, sensemaking support also carries higher epistemic risk than low-level assistance because narratives and recommendations can be persuasive; systems therefore benefit from preserving provenance, uncertainty, and auditability of suggestions and analytic steps.

Immersive environments can increase spatial capacity for externalizing intermediate results but may also fragment attention if too many elements compete in a 360-degree workspace. Workflow-oriented infrastructures such as XROps emphasize continuity by treating analysis as a configurable pipeline with preserved intermediate states and reversible exploration~\cite{Jeon2025XROps}. In the unified taxonomy, sensemaking and hypothesis development serve as the convergence point for the other task categories, with AI most valuable when it reduces friction without substituting unverifiable conclusions for scientific reasoning.

\subsubsection{Coordination and Collaborative Reasoning}
\label{sec:coordination-collaboration}
% \textit{Coordination and collaborative reasoning tasks involve shared interpretation, negotiation of meaning, role division, and maintenance of common ground among multiple analysts working within a visual analytics environment.}

Coordination and collaborative reasoning capture tasks required to establish common ground, divide labor, verify shared reference, and integrate partial findings into a negotiated interpretation. In life-science settings, collaboration is often necessary because expertise is distributed across disciplines and decisions frequently require consensus.

Prior work emphasizes that collaboration bottlenecks are often referential: when shared visual references degrade, teams may remain accurate but spend more effort grounding and verifying what is being referenced~\cite{Pettersson2009VisualReferences}. This motivates designs that support joint attention via shared pointers, legible deictic actions (e.g., pointing, gaze cues), and stable shared context.

Co-located immersive and hybrid systems instantiate these principles via shared spaces and artifacts (e.g., FIESTA)~\cite{Lee2021SharedSurfacesSpaces}, cross-device collaboration (e.g., Uplift)~\cite{Ens2021Uplift}, and personal overlays that preserve a shared reference while enabling individualized detail and tools (e.g., personal AR overlays)~\cite{Reipschlaeger2021PersonalAR}. AI assistance can further support coordination by tracking shared context, summarizing analytic state, and capturing provenance for hand-offs, but it can also undermine collaboration if it introduces divergent personalized views without clear reconciliation mechanisms. Treating coordination as a first-class task foregrounds that insights must be communicable, verifiable, and negotiable to become scientific conclusions.


\section{Visualization Modalities in Life-Science Visual Analytics}
% \textit{ Survey how each visualization environment supports or hinders analysis of biological “hairballs.”}
%\section{Visualization Modalities in Life-Science Visual Analytics}
\label{sec:visualization-modalities}
The unified task taxonomy introduced in Section~\ref{sec:task-foundations} provides a lens for characterizing analytical intent independently of any specific technological implementation. However, the manner in which these tasks are supported, constrained, or transformed is strongly influenced by the visualization modality in which analysis takes place. Different modalities afford distinct perceptual, spatial, and collaborative capabilities, shaping not only how tasks are performed but also which tasks are emphasized or become feasible. Rather than enumerating representative systems in a standalone section, we integrate system examples throughout the task-driven discussion that follows, using visualization modality and modes of AI assistance to contextualize design choices and trade-offs.

In this section, we examine how the task categories defined in Section~\ref{sec:task-foundations} manifest across visualization modalities, beginning with traditional 2D desktop environments and progressing through large displays and immersive systems. For each modality, we analyze how its characteristic affordances interact with algorithmic, adaptive, conversational, and immersive forms of AI assistance, highlighting systematic patterns in task support, design trade-offs, and open challenges. This modality-centric perspective provides the foundation for comparing AI-assisted visual analytics systems across heterogeneous analytical environments.

\subsection{Desktop 2D Environments}
% \textit{ The ubiquitous modality (e.g., Cytoscape-like tools). Discuss strengths (familiarity, reproducibility, integration with scripts) and limitations (clutter, limited spatial representation) for complex bio-data. NOTES: (1)Include some figures here from the papers illustrating heatmaps, bubblegrams,etc.; (2) Include mentions of force-directed graph examples like Cytoscape}
%\subsection{Desktop 2D Environments}
\label{sec:desktop-2d}
Desktop 2D environments remain the most common “everyday” interface for biological network and high dimensional data analysis. They are accessible, screen based, and easy to integrate into established computational pipelines. However, when desktop systems rely on classic node link diagrams as their primary representation, dense biological data quickly collapses into an unreadable hairball. Edge crossings and overplotting grow superlinearly with network size, and improvements in layout speed often only produce the same visual overload more efficiently.

A recurring design pattern across successful desktop systems is therefore semantic compression. Rather than attempting to render the full underlying structure, these systems compute interpretable structure first and visualize those summaries as the primary analytic objects. Typical forms of compression include clustering, aggregation, neighborhood construction, or redundancy reduction, with the resulting views taking the form of heatmaps, profile plots, density summaries, compact hierarchies, or reduced scatterplots. In effect, these tools refuse to draw the hairball and instead surface a smaller set of meaningful objects that better align with how biologists reason about results, such as modules, neighborhoods, enriched functions, or families of related entities.

This approach mirrors common wet lab practice, where raw instrument output is rarely acted upon directly. Instead, signals are summarized, compared, and grouped before hypotheses are formulated and validated.

At the algorithmic level, semantic compression typically combines aggregation, clustering, and redundancy reduction. In genomics, fluff and SeqPlots compress thousands of genomic regions into clustered heatmaps and aggregated signal profiles, enabling broad pattern discovery without explicit graph rendering \cite{Georgiou2016Fluff,Stempor2016SeqPlots}. For microbial community and multi omics data, Phinch uses taxonomic and metadata structure to drive interactive aggregated summaries rather than exposing raw complexity by default \cite{Bik2014Phinch}. AlignScape similarly compresses sequence similarity relationships into a self organizing map overview that supports “big picture first, details on demand” analysis \cite{FilellaMerce2024AlignScape}. For functional interpretation, GO Figure! reduces redundancy in enrichment results by grouping semantically similar GO terms and plotting representatives in a 2D semantic space, transforming long repetitive lists into interpretable summaries \cite{Reijnders2021GOFigure}.

The trade off of semantic compression is explicit. These approaches preserve global interpretability, dominant trends, and major differences between conditions, while sacrificing visibility of individual edges, rare elements, or minority patterns until users drill down. This trade off is often appropriate in biological discovery settings, where the initial question is “what are the major patterns” rather than “what is the exact path between two entities.” In pedigree analysis, VisAC uses collapsed pedigree representations to make consanguinity patterns analyzable without requiring users to trace every relationship edge by edge \cite{Borges2022VisAC}. In Cytoscape based workflows, clusterMaker2 similarly emphasizes cluster and matrix oriented summaries as a practical strategy for managing complexity and supporting downstream interpretation \cite{Utriainen2023clusterMaker2}.

From a task perspective (Section \ref{sec:task-categories}), semantic compression most strongly supports Comparison and Differentiation by enabling rapid visual comparison of conditions or cohorts through aggregated views. It also supports Sensemaking and Hypothesis Development by presenting stable, named structures such as clusters, modules, or neighborhoods that can be discussed, annotated, and tested. Compression can partially aid Navigation and Multiscale Orientation by providing a coherent overview layer, but it typically shifts Selection and Precision Interaction into a drill down workflow, where users first select an aggregate and then request the underlying elements. This design is effective when compression is reversible and traceable, and risky when summaries are opaque or irrecoverable.

Recent desktop systems in single cell and spatial biology extend the same compression first logic. TooManyCellsInteractive organizes large single cell datasets into a structured representation that supports progressive exploration rather than exhaustive point level rendering \cite{Klamann2024TooManyCellsInteractive}. For multiplexed tissue imaging, Visinity focuses on computing and exploring spatial neighborhood patterns instead of displaying raw, fully connected structures \cite{Xu2023Visinity}. Kandinsky similarly frames neighborhood analysis as a way to describe and interrogate cellular ecosystems, prioritizing computed structure over direct visualization of dense relationships \cite{Andrei2025Kandinsky}.

Finally, Transomics2Cytoscape provides an interpretability bridge for multi omics data by automating a layered, 2.5D visualization designed to keep complex trans omic relationships readable \cite{Nishida2024Transomics2Cytoscape}. While this approach introduces depth and layering, it remains a screen based desktop system, and its contribution here lies in the same compression first principle: computing and encoding structure so users can reason about it without confronting undifferentiated node link density.

Because semantic compression fundamentally changes what users can see and act on, its effectiveness should be evaluated along the axes introduced in \ref{sec:eval-alg-assistance}. In particular, evaluation must consider scalability and latency, representational fidelity, and auditability and provenance, including whether users can trace aggregate views back to the underlying biological evidence and parameter choices.

\subsection{Large Displays and Tiled Walls}
% \textit{ Wall-sized displays for collaborative, high-resolution analysis. Note strengths (multi-user collaboration, overview+detail at scale) and limitations (mostly manual interaction, no built-in AI guidance).}
% \subsection{Large Displays and Walls}
\label{sec:large-displays}

Large displays are commonly used in visual analytics to support collaborative work by placing complex data into a shared visual space. Their size allows multiple people to view the same information at once, see high-level patterns, and discuss results together. This makes them well suited for group sensemaking tasks. However, as the amount of data and the number of visual elements increase, interaction based solely on direct manipulation, such as touching or clicking, becomes difficult. Physical distance from the display, limited reach, and the need for multiple people to act at once create interaction bottlenecks that touch alone cannot address. From a task perspective, these challenges directly affect Navigation and Multiscale Orientation and Process Awareness and Provenance tasks (Section~\ref{sec:task-categories}), particularly in collaborative settings where users must remain aligned on analytic state.



Speech has therefore emerged as an important complement to touch on large displays, especially for actions that affect the overall state of the analysis. Talk to the Wall shows that users consistently prefer speech for global operations—such as clearing filters, changing sorting criteria, or switching views—while reserving touch for precise, local interactions like selecting specific items. Speech allows users to issue commands from a distance without interrupting their view of the data, reducing the need to move back and forth across the display and helping collaborators maintain situational awareness \cite{Leon2025TalkToTheWall}.



Beyond physical convenience, speech also plays a key role in coordinating group work. Talk to the Wall demonstrates that spoken commands make analytic intent visible to collaborators, helping them understand what actions are being taken and why. Rather than disrupting collaboration, speech often functions as a shared communication channel that supports awareness and alignment among team members, even when collaborators are working on different parts of the display \cite{Leon2025TalkToTheWall}. In this sense, speech is not just an input method, but a mechanism for coordinating shared analytic activity and maintaining collective process awareness (Section~\ref{sec:task-categories}).



As visual analytics systems increasingly include autonomous or semi-autonomous behavior, large displays take on an additional role as spaces for oversight and supervision. When analyses involve multiple steps, views, or computational processes, collaborators need to monitor system behavior, interpret intermediate results, and intervene when something looks incorrect or unexpected. Large displays support this kind of shared monitoring by making analytic state visible to the group. Speech further enables quick, high-level intervention—for example, pausing an analysis, redirecting focus, or resetting system state—without requiring precise spatial interaction \cite{Leon2025TalkToTheWall}.



Taken together, these findings suggest that large displays should not be treated as scaled-up desktop interfaces. Instead, they are environments where interaction must support group-level control, coordination, and oversight. Combining speech with touch allows teams to manage analytic complexity that exceeds physical reach and individual attention. As analytics systems become more active participants in the analytic process, large displays and collaborative walls are likely to function as shared control spaces, where teams collectively observe, guide, and adjust complex analyses in real time \cite{Leon2025TalkToTheWall}.

\subsection{Immersive Environments (VR, AR, CAVE, Hybrid XR) and Spatial Unfolding}
% \textit{Fully or semi-immersive systems for 3D exploration (VR headsets, AR overlays, CAVE rooms). Highlight strengths (enhanced spatial understanding, embodied navigation) and limitations (user fatigue, precision issues without AI assistance).}
\label{sec:immersive-environments}


\subsubsection{Intrinsic Spatial Data (Proteins and Anatomy): The Z Axis is Not Optional}
\label{sec:vr-intrinsic}

A substantial subset of life science data is intrinsically spatial: atoms occupy three dimensional coordinates in proteins, fluorescence localizations form three dimensional point clouds in microscopy, and anatomical reconstructions encode geometry that is itself the subject of study. In these settings, flattening to a two dimensional display does not merely change presentation; it discards depth relationships that are needed to reason about pockets, occlusion, adjacency, and pathways through space. Virtual reality environments can be effective here because stereoscopic depth cues and embodied navigation align human spatial perception with volumetric data, allowing analysts to resolve dense structure using the Z axis rather than by hiding or aggregating evidence.

\paragraph{Proteins and docking: hairballs with pockets} 
% #human spatial perception as a scientific primitive.}
For protein ligand interactions, the relevant questions are geometric: whether a ligand fits, how it threads through a transient channel, and which conformations are sterically plausible. Mishra et al.\ present an interactive molecular dynamics in virtual reality workflow in which users physically guide docking and undocking trajectories in immersive three dimensional space, and then reuse the recorded human guided trajectories and forces to parameterize and accelerate subsequent simulation for binding free energy characterization.\ \cite{Mishra2024DockingVR} This is a representative example of ``human in the loop'' advantage: rather than replacing simulation, immersion supplies a spatial reasoning substrate that can efficiently propose physically meaningful routes through a complex energy landscape.

A complementary view appears in CootVR, which adapts macromolecular model building to virtual reality by enabling direct hand driven manipulation while providing virtual reality specific visibility control over cluttered density and model geometry.\ \cite{Todd2021CootVR} The system emphasizes interaction primitives that exploit depth, including a controllable three dimensional clipping volume that constrains what portion of the density map is visible at a time, and tools designed for rapid structure placement and editing in situ. In the context of this STAR, these works motivate an assistance argument that is not primarily linguistic or predictive: immersion assists by preserving the spatial truth of the target domain and by letting users apply embodied geometric intuition during precision tasks.

\paragraph{Microscopy and anatomy: point clouds, volumes, and scale.}
In single molecule localization microscopy, the data itself is a three dimensional point cloud whose density and self occlusion can overwhelm two dimensional views. vLUME demonstrates an immersive analysis environment for such localization datasets, using virtual reality to support navigation, selection, and spatial inspection at scales that are difficult to interpret through planar projections.\ \cite{Spark2020vLUME} Related motivations appear for confocal volumes, where ConfocalVR frames immersion as a way to explore three dimensional confocal microscopy content with depth cues and interactive viewpoint control that better match the volumetric nature of the acquisition.\ \cite{Stefani2018ConfocalVR} In neuroanatomy and cellular ultrastructure, DTBIA and Journey to the Centre of the Cell demonstrate how immersive visual analytics supports the exploration of complex anatomical reconstructions by preserving spatial context and scale, allowing users to reason about morphology, connectivity, and spatial organization without collapsing structures into a single planar view. ~\cite{Yao2025DTBIA,Johnston2018Journey}

\paragraph{Capability versus access: from high performance desktop engines to web based VR.}
Not all intrinsic spatial analysis requires full room scale immersion, but many pipelines still hinge on interactive three dimensional exploration at scale. VTX targets the rendering bottleneck directly, enabling interactive visualization of extremely large molecular systems (for example, whole cell scale bead models) through high performance level of detail and GPU oriented rendering strategies.\ \cite{Rousset2025VTX} At the other end of the access spectrum, ProteinVR illustrates how browser based virtual reality can lower deployment friction for structural exploration and communication by making immersive molecular viewing available without specialized installation workflows.\ \cite{Cassidy2020ProteinVR} Together, these systems support a pragmatic narrative for this STAR: intrinsic spatial domains motivate a continuum from advanced performance engines to broadly accessible web based immersion, with the common theme that three dimensional perception is part of the scientific signal.

\paragraph{Communication and public understanding.}
Finally, intrinsic spatiality is not only an expert analysis concern; it can also support public communication when the structure is the message. Corona VRus Coaster exemplifies the use of immersive interaction to convey viral structure and spatial relationships to non expert audiences, treating three dimensional form as the central explanatory object rather than as a stylistic enhancement.\ \cite{CalveloPineiro2025CoronaVRusCoaster}

\subsubsection{Abstract Data (Genomics and Networks): The Hairball in the Headset}
Many life science datasets are naturally expressed as graphs but do not come with intrinsic spatial coordinates, for example gene regulatory networks, gene coexpression networks, and multilayer interaction networks. In these cases, immersive visualization does not inherit a meaningful three dimensional coordinate system from the underlying phenomenon. Instead, depth becomes an additional design degree of freedom that can improve separation, but can also amplify occlusion, perspective ambiguity, and edge clutter. As a result, simply placing nodes in space is rarely sufficient. For abstract networks, the value of VR comes from better separation and controlled disclosure rather than from raw node count.

\paragraph{Immersive 3D Network Layouts for Decluttering and Interactive Analysis}
NeuroCave illustrates this principle clearly. Rather than treating three dimensional space as an unstructured canvas, it introduces layouts that impose geometric constraints to reduce clutter. When clusters do not have meaningful spatial positions, NeuroCave maps communities onto Platonic solid faces so that modules become spatially separated, and users can further rearrange clusters to expose dense regions during analysis \cite{Keiriz2018NeuroCave}. NeuroCave also treats edge density as a first class problem: edges can be hidden by default and revealed on demand from a selected root node, while crossings are mitigated through force directed edge bundling implemented on the GPU for interactive use \cite{Keiriz2018NeuroCave}. Importantly for the STAR narrative, NeuroCave is also a web based, VR compatible system, which makes it a concrete example of how zero install delivery can coexist with immersive network analytics \cite{Keiriz2018NeuroCave}. Earlier immersive network systems such as iCAVE provide a complementary baseline by demonstrating that specialized three dimensional layouts and three dimensional edge bundling are essential mechanisms for decluttering biological graphs across desktop, stereoscopic, and CAVE style settings \cite{Liluashvili2017iCAVE}.

\paragraph{GeneNet VR: Accessibility, Performance, and the Limits of Dense Network Visualization}
GeneNet VR provides a useful contrast because it targets accessibility through inexpensive standalone hardware. It implements interactive exploration of large gene to gene interaction networks on an Oculus Quest class headset and reports meeting the 72 FPS comfort target on networks with thousands of genes \cite{Fernandez2021GeneNetVR}. This result supports feasibility, but it also reinforces the critique above: performance and immersion alone do not eliminate the hairball. The authors emphasize interaction patterns such as selection, filtering, and scaling, and they note that further work is required to evaluate benefits for real analysis and knowledge discovery tasks \cite{Fernandez2021GeneNetVR}. In practice, this motivates a design stance for abstract graphs in VR: the goal is not more nodes, but better separation and better mechanisms for revealing structure progressively.

\paragraph{Hardware Trade-offs in Standalone vs Web-based}
This hardware trade off also appears in the contrast between standalone and web based immersive systems. SinglecellVR exemplifies a web based approach for single cell data visualization in virtual reality that is intended to lower barriers through a browser mediated workflow and low cost viewing options \cite{Stein2021singlecellVR}. In contrast, higher end systems such as CellexalVR argue that analytic interaction depends on capabilities that lightweight mobile viewers struggle to provide, including high resolution GPU backed rendering and fully tracked hands on manipulation \cite{Legetth2021CellexalVR}. CellexalVR also frames VR as an expandable workspace for integrated analysis, supporting multiple reductions and in session derivations (for example differential expression and trajectory related views), which matters when the analytic task is comparative reasoning rather than a single static view of a dense embedding \cite{Legetth2021CellexalVR}. These examples show how accessibility choices can shape which forms of assistance are realistic: web based deployment can broaden reach, but may constrain interaction richness, while workstation class VR can enable deeper analysis at higher setup cost.

\paragraph{Anchoring Abstract Omics to Physical Reality}
Systems for spatial transcriptomics move in this direction by binding gene expression back to tissue geometry. VR Omics, for example, targets multi slice spatial transcriptomics and supports interactive exploration in three dimensions with optional VR integration, including workflows that leverage manual alignment and spatial context to interpret molecular patterns \cite{Bienroth2025VROmics}. This anchoring changes the role of immersion: the headset is no longer used to read an arbitrary three dimensional graph, but to inspect genomic patterns in a physically meaningful coordinate frame.

\paragraph{Immersive VR for Cohort Separation and Layer Disentanglement}
Finally, several immersive systems demonstrate that VR can be especially effective for cohort separation and layer disentanglement, even when the underlying data are abstract. VROOM uses an immersive similarity space for oncology cohorts, linking clusters in three dimensions to familiar genomic panels (for example heatmaps and other coordinated views) so users can separate groups and drill down into details without overplotting everything into a single hairball \cite{Lau2022VROOM}. Likewise, conceptual work on immersive multilayer animal behaviour networks emphasizes that the key benefit of immersion is the ability to separate and manipulate layers in three dimensions to reduce overlap and support comparison, rather than to force a dense network into a single monolithic view \cite{Feyer2024AnimalBehaviourImmersive}. 

Together, these examples show that VR is not a universal remedy for abstract life-science data, but a conditional advantage that depends on how three-dimensional space is used. When immersion is paired with structured layouts (e.g., constrained geometric scaffolds), progressive disclosure (e.g., on-demand edge reveal and thresholding), and explicit separation of layers or cohorts, the headset becomes a decluttering instrument that improves comparative reasoning. By contrast, when VR merely ``adds depth'' to an unconstrained node--link diagram, occlusion and perspective ambiguity can worsen the hairball, shifting effort from biological interpretation to perceptual triage. In this sense, the benefit of VR for abstract genomics and networks is not ``more nodes in 3D,'' but better separability and controllable visibility that preserve analytic intent.

\subsubsection{Augmented and Mixed Reality: Situated Analytics}
\label{sec:ar-mr-situated}

Augmented reality (AR) and mixed reality (MR) support a ``situated'' layer of life science visual analytics in which data views are integrated into the physical laboratory context rather than replacing it with a fully virtual workspace. This orientation matters because many biomedical analysis workflows are inherently hybrid: teams collaborate around shared displays, instruments, and specimens, while individuals need private analytic controls, annotations, and alternative views. Reipschl\"{a}ger et al.\ formalize this hybrid workflow by combining a shared large interactive display with personal head worn AR overlays, enabling each analyst to see individualized views and tools without disrupting the shared reference frame of the group \cite{Reipschlaeger2021PersonalAR}. Their design space demonstrates how AR can offload auxiliary encodings and interactions into personal overlays (for example, extended axes, embedded views, and personal brushing and linking), reducing visual crowding on the shared screen while improving multi user coordination.

A second requirement for situated analytics is geometric: once views move into the physical environment, their spatial arrangement becomes a primary determinant of readability and cross view reasoning. Wen et al.\ study view layout for multiple view representations in immersive visualization and propose an automatic layout adaptation strategy that uses a cylindrical reference frame around the user together with a force directed optimization to maintain view visibility and balanced view to user and view to referent distances \cite{Wen2023ViewLayout}. Their controlled study shows that such structured placement can improve performance on cross view tasks (for example filtering and connecting) compared to alternative layout paradigms, supporting the broader claim that situated AR should treat view management as an algorithmic problem rather than as ad hoc placement.

However, arranging views in space does not, by itself, explain how analysts connect abstract data marks back to physical referents. Doerr et al.\ provide a concrete interaction mechanism via ``situated brushing and linking,'' where brushing marks in a situated scatterplot triggers visual highlighting of corresponding referents in the environment \cite{Doerr2024SituatedHighlighting}. In a VR proxy of a situated setting, they evaluate multiple highlighting encodings (including color, outline, links, and arrows) and report that simple, high contrast highlighting yields the fewest identification errors, while more elaborate guidance can introduce clutter when many targets are selected. For life science workflows, this mechanism is directly relevant to the lab: the referent is often a specimen, slide, or instrument context, and the analytic problem is not only reading a chart but reliably mapping chart selections back onto physical objects and locations.

Finally, MR systems demonstrate how situated analytics can extend beyond generic interaction metaphors into domain specific translational pipelines. Iakab et al.\ present an end to end 3D MALDI imaging platform that culminates in a mixed reality tool for exploring volumetric spatial omics data using video pass through and hand tracked interaction, allowing users to remain present in their physical workspace while manipulating and inspecting dense molecular distributions in three dimensions \cite{Iakab2025FromSampleToMixedReality}. When physical deployment is difficult, situatedness can also be approximated through captured context: Iglesias et al.\ overlay augmented situated visualizations on a photorealistic reconstruction of a real environment in VR, integrating feature extraction and reconstruction workflows so that analytic overlays remain registered to a recognizable setting \cite{Iglesias2021EnhancedPhotorealistic}. Across these works, the situated layer reframes immersion as contextual augmentation: the goal is not to isolate the analyst inside a headset, but to keep analytic reasoning anchored to the social and physical realities of laboratory work while providing algorithmic support for layout, linking, and attention guidance.

% \subsection{Modality as a Determinant of Task Load and Cognitive Strategy}
%  Synthesize how each modality influences cognitive workflow: e.g., 2D supports precise annotation but overloads on big data; VR reduces occlusion but adds navigation burden. Discuss which AI assistance types are most needed per modality.
%  (Transition: emphasize that limitations of each modality motivate integrating AI assistance, leading into Section~5.)

\subsection{Modality as a Determinant of Task Load and Cognitive Strategy}
\label{sec:modality-task-load}

Across the modality survey, a consistent pattern emerges, visualization modality does not only change how data are rendered, it changes which parts of the analytic workflow are cognitively cheap, which parts become expensive, and which strategies analysts adopt to cope with density. The same underlying biological structure, a crowded protein assembly, a single cell embedding, or a gene regulatory network, can be approached as a reading task, a navigation task, or a coordination task depending on whether it is placed on a desktop monitor, a wall display, a headset, or a mixed reality workspace. In practical terms, modality shifts effort between perception, interaction, and memory, and those shifts determine when analysts can stay in a smooth sensemaking loop versus when they get trapped in view management.

On conventional 2D desktops, the primary advantage is precision and throughput. Mouse and keyboard input make selection, annotation, scripting, and reproducible parameter control fast, and the surrounding ecosystem of statistical and bioinformatics tools is mature. The cost is compression. Large, multiscale datasets are forced into a limited screen area, so analysts compensate with aggressive filtering, repeated view switching, and external notes to maintain context. For dense graphs and high dimensional point clouds, this turns navigation and comparison into bookkeeping, where cognitive load is dominated by preserving orientation rather than interpreting structure. In this regime, the most valuable assistance tends to be algorithmic, to compute structure and reduce density through layout, clustering, embeddings, and abstraction, and conversational, to lower the cost of querying and explanation without repeated manual configuration.

Large displays and co present environments shift the bottleneck from individual precision to shared reference. They increase bandwidth for overview and discussion, but they also raise coordination costs when multiple people must stay synchronized on what is being referenced, which subset is selected, and which view state is current. Hybrid approaches that pair a shared surface with private overlays, for example personal head mounted augmentation aligned to a large interactive display, aim to preserve a common operational picture while giving individuals role specific detail layers~\cite{Reipschlaeger2021PersonalAR}. In these settings, adaptive and attention oriented assistance becomes central, systems must manage view placement, highlight relevant elements, and support linking between shared and personal views, rather than only optimizing a single visualization in isolation.

Immersive environments add stereoscopic depth, scale, and embodied perspective, which can make dense spatial data and complex connectivity patterns more legible, but they also change interaction into a continuous navigation problem. Viewpoint control, occlusion management, and selection precision become first order concerns, especially for abstract data where placing nodes in 3D can create new occlusions unless layouts and interaction are constrained, as illustrated by systems that combine structured layouts with coordinated comparison mechanisms~\cite{Keiriz2017NeuroCave,Ng2024ExoEgo}. Techniques such as guided inside out tours through crowded geometry~\cite{Alharbi2023Nanotilus} and focus plus context selection mechanisms that bring distant targets into comfortable reach~\cite{Dai2025MagicPortals} show a broader lesson, immersion becomes analytically usable when intelligence is embedded into navigation and interaction, not only into pre processing.

Because each modality amplifies some tasks while penalizing others, effective life science workflows increasingly rely on cross platform ecosystems that allow analysts to move between devices without losing analytic state. Web based and workflow oriented systems provide concrete models for this, ranging from late binding desktop to WebXR immersion~\cite{Keiriz2017NeuroCave}, to collaborative browser first environments~\cite{CortesRodriguez2024MolecularWebXR,Borowski2025DashSpace}, to hybrid PC plus VR interfaces that preserve precise input alongside spatial organization~\cite{Tong2025SpatialHybridUI}. Operational frameworks such as XROps further emphasize that the analytic pipeline, not the headset, is the unit of design, enabling data processing and rendering stages to be recomposed as tasks change~\cite{Jeon2025XROps}.

In light of these considerations, these modality specific trade offs indicate where AI assistance is most needed. Algorithmic assistance is critical when density must be reduced and structure must be computed before it can be interpreted. Adaptive assistance is most valuable when users transition between scales, views, and devices, and when systems must personalize defaults without breaking analytic continuity. Conversational assistance reduces interaction friction, particularly when precise text input is otherwise awkward, and it supports interpretation through lightweight explanation. Immersive AI assistance is indispensable in XR, where the system must stabilize input, guide attention, and manage occlusion in a full field environment. These constraints motivate the vertical dimension of our conceptual model, AI assistance is the mechanism that makes heterogeneous visual analytics workflows coherent across modalities, rather than a cosmetic add on.

\section{AI Assistance in Life-Science Visual Analytics (Vertical Dimension of the Conceptual Model)}

If Section~\ref{sec:visualization-modalities} characterizes where biological visual analytics happens, across desktops, large displays, and immersive environments, this section characterizes how analysis is augmented. We use \emph{AI assistance} broadly to include machine learning, optimization, and rule based automation that intervenes in the analytic loop, sometimes by transforming the data before it is shown, sometimes by adapting the interface during interaction, and increasingly by mediating communication between analyst and system.

To make the landscape comparable across modalities, we organize prior work by assistance type rather than by display. The subsections that follow survey four recurring roles. \emph{Algorithmic assistance} automates structure extraction and visual simplification, for example layouts, clustering, embeddings, and multiscale abstraction. \emph{Adaptive assistance} closes the loop, using interaction traces and feedback to personalize views, recommend actions, or reconfigure representations as intent changes. \emph{Conversational assistance} introduces natural language as an interaction layer for querying, steering, and explanation. Finally, \emph{immersive AI assistance} embeds intelligence directly into XR interaction, including guided navigation, occlusion aware visibility control, gaze and gesture fusion, and precision support for selection and manipulation.

These assistance modes are not mutually exclusive, many systems combine them, and their relative importance depends on modality and on the task categories introduced in Section~\ref{sec:task-categories}. The goal of this section is therefore twofold, to summarize the mechanisms that constitute each assistance type, and to show how they redistribute task load across navigation, comparison, selection, sensemaking, and collaboration. This framing also exposes recurring challenges, including maintaining analyst agency, preventing automation induced bias, and preserving reproducibility when assistance is adaptive or conversational, which we revisit in later design and evaluation discussions.


% \section{AI Assistance in Life-Science Visual Analytics (Vertical Dimension of the Conceptual Model)}
% %  Survey the roles of AI assistance types across all visualization modalities.
% \subsection{Algorithmic Assistance (Foundational AI for Visual Analytics)}
% \textit{ Pre-computed or on-demand computational techniques (clustering, dimensionality reduction, layout algorithms, etc.) that enhance scalability and pattern detection. Strengths (objective structure finding, reproducibility) vs. limitations (static, not user-adaptive).}
%  Survey the roles of AI assistance types across all visualization modalities.

\subsection{Algorithmic Assistance (Foundational AI for Visual Analytics)}
% \textit{Pre-computed or on-demand computational techniques (clustering, dimensionality reduction, layout algorithms, sparsification, etc.) that enhance scalability and pattern detection. Strengths include reproducibility and the ability to expose latent structure, limitations include distortion, opacity, and weak alignment with user intent when used as a one-shot preprocessing step.}

Algorithmic assistance is the most “foundational” form of AI in visual analytics because it reshapes the analytical substrate before any interaction happens. In life-science workflows, this reshaping is often what determines whether a dataset is even navigable, for example whether a single-cell atlas becomes a traversable landscape or remains a dense, uninterpretable cloud, whether a knowledge graph becomes a readable scaffold or stays a hairball. We organize algorithmic assistance around three recurring mechanisms: (i) \emph{embedding and dimensionality reduction}, which moves complexity into a latent geometry, (ii) \emph{sparsification and backbone extraction}, which removes edges while claiming to preserve specific structural guarantees, and (iii) \emph{semantic aggregation and abstraction}, which replaces redundant pathway and ontology outputs with a compact conceptual map. Across all three, the key question is not only “does it look cleaner,” but “what truth claims still hold after the reduction.”

\subsubsection{Embeddings / Dimensionality Reduction (“move complexity into latent geometry”)}

\noindent\textbf{Mechanism definition (what the algorithm does).}
Embeddings and dimensionality reduction construct a low-dimensional coordinate system whose distances and neighborhoods are intended to stand in for high-dimensional similarity. In methods like SNE and t-SNE, the embedding is the solution to an optimization problem that attempts to preserve local neighborhood relations under a compressed geometry, producing a map that users can navigate and interpret visually \cite{hinton2002sne,vandermaaten2008tsne}.

\noindent\textbf{Hairball trade-off (what it preserves vs.\ sacrifices).}
The benefit is immediate decluttering, the “hairball” becomes a spatial field where proximity approximates similarity. The cost is that preservation is partial and scale-dependent, local neighborhoods can be emphasized at the expense of global topology, and visually crisp cluster boundaries can be artifacts of hyperparameters, density variation, or confounds rather than biology. In other words, embeddings reduce visual complexity by relocating it into a learned geometry whose distortions can be hard to see.

\noindent\textbf{Task-category mapping (Section~\ref{sec:task-categories}).}
Embeddings most directly support \textbf{Navigation and Multiscale Orientation} by turning search and overview into spatial movement through a latent landscape, and they support \textbf{Comparison and Differentiation} when clusters and gradients correspond to stable biological structure. However, they can actively harm \textbf{Sensemaking and Hypothesis Development} if users treat the map as ground truth without diagnostics, because interpretation becomes anchored to geometry that may not be globally trustworthy.

\noindent\textbf{Evidence paragraph (2--4 anchor + 2--6 supporting papers).}
The classic SNE and t-SNE line of work formalizes the core promise, neighborhood structure in the original space is approximately preserved in a 2D or 3D map that users can inspect and traverse \cite{hinton2002sne,vandermaaten2008tsne}. More recent biological embedding work increasingly treats verification as a first-class requirement, for example, PARE operationalizes counterfactual checking by producing covariate-adjusted distance structures so analysts can ask what changes when batch or other confounds are removed \cite{chen2024pare}, and Haisu explicitly incorporates hierarchical intent into nonlinear dimensionality reduction to better align embeddings with multiscale biological structure \cite{vanhorn2022haisu}. Domain-specific models further show how “the embedding” is often not a generic scatterplot input, but an algorithmic object that encodes priors and structure: PAST learns latent features for spatial transcriptomics by combining spatial graphs with reference information, producing embeddings that improve downstream spatial domain identification and related tasks \cite{Li2023PAST}, while PoincaréDMT adopts hyperbolic geometry to better represent hierarchical and branching structure in single-cell data, pairing geometric preservation goals with attribution methods for marker interpretation \cite{Xu2025PoincareDMT}. Taken together, these works support a design stance of “trust, but verify the embedding,” where the visualization is only as reliable as the stability, confound control, and provenance of the learned geometry.

\noindent\textbf{Evaluation hook (point to \ref{sec:eval-alg-assistance} axes).}
Embedding-based assistance should therefore be evaluated along the \ref{sec:eval-alg-assistance} axes, scalability of computation and interactivity, fidelity of preserved neighborhoods and global structure, and auditability through stability diagnostics, confound tests, and end-to-end provenance.

\subsubsection{Sparsification and Backbones (“what guarantees survive?”)}

\noindent\textbf{Mechanism definition (what the algorithm does).}
Sparsification reduces a dense graph by removing edges to obtain a backbone, a subgraph intended to retain “important” structure while discarding redundancy. Unlike visual decluttering applied at render time, backbone extraction changes the graph itself, often guided by structural criteria such as preserving shortest-path geometry, connectivity, or statistically significant weighted edges.

\noindent\textbf{Hairball trade-off (what it preserves vs.\ sacrifices).}
Sparsification is not just an optimization, it is an epistemic commitment about which relations matter. A backbone can preserve particular guarantees, for example, approximate reachability structure or key transmission pathways, but it necessarily sacrifices completeness, including weak ties that might be biologically meaningful in specific contexts. The central trade-off is therefore between interpretability and coverage, and that trade-off must be explicit.

% \noindent\textbf{Task-category mapping (Section~\ref{sec:task-categories}).}
Backbones most directly enable \textbf{Selection, Focus, and Precision Interaction} because they reduce the candidate space of edges and neighborhoods to something a user can actually inspect, filter, and annotate. They also support \textbf{Navigation and Multiscale Orientation} by making global structure traversable, and \textbf{Comparison and Differentiation} when different backbones expose condition-specific connectivity patterns. For \textbf{Sensemaking and Hypothesis Development}, sparsification only helps when guarantees and provenance are visible, otherwise hypotheses may be built on edges that survived for algorithmic reasons the user does not understand.

% \noindent\textbf{Evidence paragraph (2--4 anchor + 2--6 supporting papers).}
Comparative backbone work makes clear that different sparsification rules preserve different properties, and no single method is universally “correct,” the choice determines what structural truths remain legible \cite{Yassin2025BackboneExtraction}. In an applied biomedical setting, myAURA operationalizes this perspective by sparsifying a multilayer biomedical knowledge graph using a metric-backbone approach to yield a far smaller, more interpretable structure for epilepsy management, while treating the retained edges as the backbone of meaningful relations for inference, recommendation, and exploration \cite{Correia2026myAURA}. Importantly, this is exactly where sparsification becomes a scientific claim rather than a convenience, the system is making a statement about which edges are primary enough to drive interpretation and downstream action. This framing generalizes beyond epilepsy, dense biological interaction graphs and integrated knowledge graphs often require a backbone layer before any interactive visual analysis is feasible, but the backbone must be defensible relative to the analyst’s questions.

% \noindent\textbf{Evaluation hook (point to \ref{sec:eval-alg-assistance} axes).}
Backbone extraction should be evaluated in \ref{sec:eval-alg-assistance} terms as a coupled scalability, fidelity, and auditability problem, can it be computed fast enough for interactive use, what structural properties are preserved or broken, and can users inspect what was removed and why.

\subsubsection{Semantic Embeddings and Abstraction for Pathway Results (“compress redundancy into concepts”)}

\noindent\textbf{Mechanism definition (what the algorithm does).}
A large fraction of life-science “hairballs” are not only node link graphs, they are redundant, overlapping lists of pathways, gene sets, and ontology terms produced by enrichment and differential analysis pipelines. Semantic abstraction methods address this by embedding pathway terms into a vector space, clustering them by similarity, and then visualizing cluster representatives or conceptual neighborhoods rather than every term individually.

\noindent\textbf{Hairball trade-off (what it preserves vs.\ sacrifices).}
These methods preserve semantic relatedness and reduce redundancy, helping users see themes rather than duplicates. The sacrifice is that gene-level mechanistic detail and fine-grained distinctions between closely related pathways can be obscured when terms are merged or abstracted, and the embedding model itself introduces a new layer of potential bias.

% \noindent\textbf{Task-category mapping (Section~\ref{sec:task-categories}).}
Semantic aggregation strongly supports \textbf{Comparison and Differentiation} when analysts contrast conditions and need to see which functional themes diverge, and it supports \textbf{Selection, Focus, and Precision Interaction} by reducing thousands of terms to a manageable set of representative candidates. It also directly accelerates \textbf{Sensemaking and Hypothesis Development}, because it provides a structured narrative substrate, a compact “map of mechanisms” that can be cross-checked against underlying genes and evidence.

% \noindent\textbf{Evidence paragraph (2--4 anchor + 2--6 supporting papers).}
PAVER exemplifies embedding-driven consolidation for pathway enrichment output, embedding pathway terms, clustering them, and selecting representative pathways to produce concise visual summaries instead of long redundant lists \cite{ODonovan2024PAVER}. Mondrian Map pushes the abstraction further by using language model embeddings to spatially arrange pathway tiles in a Mondrian-style layout, encoding differential activity through size and color and highlighting limited crosstalk connections, explicitly replacing dense node link representations with a structured conceptual surface \cite{AlAbir2024MondrianMap}. Both systems illustrate a key algorithmic-assistance pattern for “hairballs to hypotheses,” when mechanistic interpretation is the goal, it can be more faithful to show an audited summary of functional concepts than to overwhelm users with every pathway term and every edge.

% \noindent\textbf{Evaluation hook (point to \ref{sec:eval-alg-assistance} axes).}
These abstractions should be evaluated in \ref{sec:eval-alg-assistance} terms with scalability to large enrichment outputs, fidelity of semantic grouping relative to biological ground truth or expert judgment, and auditability that exposes which genes and databases support each tile or cluster, and which embedding model and version produced the geometry.


\subsection{Adaptive Assistance}
% \subsection{Adaptive Assistance (Systems That Respond to Users, Data, and Context)}
 % \textit{Interfaces that adjust in real-time to user behavior or data context (e.g., focus highlighting, recommended next steps, level-of-detail adjustments). Note how this reduces cognitive load and speeds analysis, and discuss challenges (user modeling complexity, potential opacity).}
 
Adaptive assistance is system behavior that changes the visualization or interaction in response to the user, grounded in three capabilities: (i) user modeling to predict interaction patterns and detect exploration bias; (ii) intent understanding to infer higher-level goals from interaction logs (e.g., GNN-based inference over structured interaction traces); and (iii) proactive guidance/recommendation that suggests what to examine next (insights) and what to do next (actions). We use DataSite as an exemplar of proactive insight computation and recommendation, the deep-learning interaction recommender as an exemplar of action suggestion, and the unified comparison of user-modeling techniques to elevate bias detection as a first-class requirement \cite{Cui2019DataSite,Li2023DiverseInteractionRecommendation,Ha2022UserModeling,Wang2024GNNIntent}.

Adaptation can reduce cognitive burden but can also steer exploration---creating ``filter bubble'' dynamics where the system's suggestions narrow what gets seen and, consequently, what gets concluded. Therefore adaptive systems must surface provenance: why a recommendation is made, what signals were used (interaction history, inferred intent, data priors), and how to override it (disable personalization, request diversity, lock a view/facet/scale, or widen the search space). Bias detection should actively monitor when adaptation is concentrating attention too early, and guidance policies should explicitly trade off relevance with coverage to avoid premature convergence \cite{Ha2022UserModeling,Steichen2019TowardsAdaptiveInfoVis}.

Adaptive guidance also needs audience-aware evaluation: what counts as ``good guidance'' differs when judged by visualization experts (appropriateness, soundness of rationale, risk of biasing) versus end users (in-situ usefulness while solving tasks) \cite{Ceneda2024HeuristicDualEvaluation}. Tied to Section~\ref{sec:task-categories} tasks, adaptive assistance supports Navigation \& Multiscale Orientation via adaptive viewpoint/scale guidance and proactive focus routing, and Selection/Focus/Precision via intent-driven filtering plus recommendation/suppression of irrelevant items \cite{Wang2024GNNIntent}. For Sensemaking \& Hypothesis Development, insight recommendations can accelerate early hypothesis formation, but must be designed to prevent premature convergence by making uncertainty, alternatives, and override mechanisms salient \cite{Cui2019DataSite,Li2023DiverseInteractionRecommendation}.


% \subsection{Conversational Assistance (LLMs as Visual Analytics Co-Analysts)}
% \textit{ Natural language interfaces enabling users to query and direct analysis in plain language. Describe capabilities (asking questions about data, getting explanations, instructing the system) and limitations (LLM hallucinations, need for domain grounding).}

\subsection{Agentic Orchestration (Conversational Interfaces for Autonomous Analytics)}
\label{sec:agentic-orchestration}
As biological datasets grow in size and complexity, it becomes increasingly difficult for scientists to manage analysis through step-by-step manual interaction. Exploring large networks, high-dimensional cohorts, or multi-view datasets often requires long sequences of filtering, parameter tuning, and view switching. These low-level interactions can distract from scientific reasoning and make it harder to keep track of analytic intent. In this setting, natural language interfaces (NLIs) are no longer best understood as tools for asking isolated questions, but as mechanisms for managing and guiding analytic workflows \cite{Jia2024LightVA,Chen2024ProactiveVA}. From the perspective of analytic tasks, this shift primarily supports Query Refinement and Hypothesis Development and Comparison and Pattern Reasoning (Section~\ref{sec:task-categories}), where users reason iteratively rather than issuing isolated commands.



Earlier work on NLIs for visualization focused on translating natural language requests into specific visual outputs, such as generating a chart or applying a filter \cite{Wang2024DomainBridge}. While this approach lowers interaction barriers, it still requires users to decide each analytic step and issue commands one at a time. More recent systems move beyond this model by allowing users to express high-level analysis goals, which the system then carries out as a sequence of coordinated actions. LightVA illustrates this shift by treating analysis as a planning problem: the user states an objective (e.g., comparing groups or exploring trends), and the system breaks that objective into ordered steps such as data selection, transformation, visualization, and statistical comparison \cite{Jia2024LightVA}. Crucially, these steps are made visible, directly supporting Process Awareness and Provenance tasks by allowing users to inspect and adjust the workflow as it unfolds (Section~\ref{sec:task-categories}).



This goal-driven approach aligns closely with how scientific analysis is performed in practice. Scientists typically think in terms of aims and workflows rather than individual interface operations. PhenoAssistant demonstrates how this model can be applied in a biological setting by coordinating multiple specialized agents, each responsible for a different part of a phenotyping pipeline \cite{Kim2024PhenoAssistant}. Instead of manually managing each stage, the user supervises the process, checks intermediate results, and redirects the analysis when needed. The interface therefore functions less like a command line and more like a workspace for overseeing analytic progress.



Conversation remains an important part of these systems, but its role changes. Rather than issuing individual commands, users engage in dialogue to refine goals, clarify assumptions, and adjust ongoing analysis. Systems such as PhenoFlow and CausalChat show how iterative conversation supports this kind of refinement, allowing users to progressively narrow cohorts, revise causal models, or explore alternatives through back-and-forth interaction \cite{Kim2024PhenoFlow,Guo2024CausalChat}. In these cases, conversation helps maintain continuity of intent while the system handles increasingly complex analytic work.



Some systems also introduce limited forms of proactive behavior. ProactiveVA explores how an AI system can suggest next steps or flag potential issues without being explicitly prompted, such as recommending additional comparisons or highlighting unusual patterns \cite{Chen2024ProactiveVA}. While this can reduce cognitive burden, it also introduces new risks if system behavior is not transparent or controllable. As a result, such systems emphasize clear explanations, reversibility, and user oversight.



Taken together, these examples suggest that conversational assistance in visual analytics is evolving into agentic orchestration, where language is used to initiate, guide, and supervise multi-step analytic workflows. Rather than replacing scientific judgment, these systems aim to offload procedural complexity while keeping users responsible for interpretation and decision-making. This shift has important implications for evaluation, as discussed in Section~\ref{sec:conversational-assistance}, where trust depends not only on results, but on how clearly analytic decisions and system behavior are exposed to the user.




\subsection{Immersive AI Assistance: Intelligence Embedded in XR Analytics}
\label{sec:immersive-ai}

Immersive environments such as VR, AR, and CAVE systems offer a large spatial workspace for visual analytics, but life science data quickly exposes interface limits. Many systems still rely on the controller based ``laser pointer'' metaphor (ray casting) and on \emph{skeuomorphic} interaction design, meaning interfaces that borrow familiar real world objects and actions (for example, virtual desks, dashboards, or literal tools) to make a digital system feel familiar. Skeuomorphism can reduce the learning curve, as seen in VROOM, which lets users edit ontology graphs using virtual scissors and glue \cite{Vinnikov2022VROOMOntology}. However, for dense biological point clouds and networks, naive pointing and mid air manipulation often becomes slow and error prone, and sustained reaching leads to ``gorilla arm'' fatigue (arm and shoulder strain from prolonged mid air interaction). These issues motivate immersive AI assistance, where the system actively mediates between noisy human input and the underlying data model, instead of treating immersion as only a larger display.

A useful lens for thinking about immersive interaction is the contrast between \emph{hard} and \emph{soft} magic, adapted from narrative theory. Hard magic systems have explicit rules and predictable outcomes, while soft magic systems are intentionally ambiguous  \cite{SandersonFirstLaw}. Wizualization adopts this framing for immersive analytics by treating gestures and speech as a rule governed grammar for constructing and transforming views, rather than as navigation through a virtual office \cite{Batch2024Wizualization}. The practical value of this metaphor for XR analytics is learnability: when interaction has a clear syntax and consistent semantics, users can form stable mental models, and the system can provide assistance such as disambiguation, suggestions, and recovery when input is partial or imprecise.

For biology, this suggests a shift from controller based interaction toward intent based interaction. Because biological scenes are dense and often multi scale, the interface should combine multiple signals, including what the analyst looks at, what they reach for, and what the data permits, to infer intent (select this cluster, follow this trajectory, dock this ligand) and execute it safely. Existing systems already illustrate three complementary assistance layers. First, \emph{navigational assistance} can steer viewpoint through clutter: Nanotilus automatically generates inside out guided tours through crowded molecular environments by planning traversable camera paths through voids and applying view dependent sparsification so the user does not become trapped in geometry or overwhelmed by occlusion \cite{Alharbi2023Nanotilus}. Second, \emph{motor and physics assistance} can stabilize manipulation by snapping interaction to valid targets. In immersive molecular docking, Mishra et al. show that human guided VR manipulation, constrained by physically meaningful forces and geometry, can produce useful docking and unbinding trajectories that are then reused to accelerate subsequent simulation runs \cite{Mishra2024DockingVR}. For selection in room scale point clouds, Magic Portals bring distant regions into comfortable reach and can add haptic confirmation, reducing selection jitter and mid air fatigue while maintaining global context \cite{Dai2025MagicPortals}. Third, \emph{attention assistance} is essential in 360 degree spaces, where relevant items may be out of view. Doerr et al. empirically compare highlighting techniques for situated brushing and linking, showing how visual links and animated cues can guide attention from an abstract view to concrete referents, while also revealing how some cues can become clutter when selections grow \cite{Doerr2024SituatedHighlighting}. Even outside the life sciences, VR training for SONAR interpretation reinforces both the opportunity and the risk of this kind of guidance: an egocentric conformal overlay improved speed and accuracy, but it could also create over reliance when the aid was removed \cite{Salamon2025TrainingSONAR}.

Collectively, these works demonstrate that effective immersive interfaces for life science analytics are less about giving users more virtual tools, and more about building a cooperative ``copilot'' that infers intent and manages degrees of freedom. In practice, this means fusing multimodal signals (gaze, proximity, gesture, and model constraints) to choose viewpoints, constrain actions, and direct attention without overwhelming the user. This framing also sets up the role of haptics in Section \ref{sec:visceralization}: tactile feedback can serve as an additional confirmation channel for selection and manipulation, helping immersive assistance feel precise rather than fragile \cite{Dai2025MagicPortals}.

\subsection{Data Physicalization and Visceralization: From Visualizing to Visceralizing}
\label{sec:visceralization}

Immersive analytics is often framed as ``more space for more charts,'' but this is only part of what XR can offer. For the life sciences, many analytic questions are grounded in physical reality: size, density, crowding, and proximity. A genome, a tissue sample, or a molecular environment can be mathematically abstracted, but the phenomena being studied still have real scale and material constraints. In this sense, ``immersion'' is incomplete if it remains purely optical. A key opportunity is to use XR to make analysts \emph{feel} structure and scale, not just see it.

Lee et al.\ introduce the term \emph{data visceralization} to describe VR experiences that restore a sense of physical reality to quantitative data, aiming for intuitive understanding through embodied scale and presence rather than only symbolic encodings \cite{Lee2021DataVisceralization}. Their central argument is that abstraction in visualization can sever a user’s connection to what a unit or measurement corresponds to in the real world. VR can partially repair this connection by placing people in a data driven scene that preserves a one to one relationship between representation and quantity whenever possible. Their prototypes emphasize that ``how big'' and ``how fast'' can be understood differently when the user experiences those magnitudes spatially at human scale, and they report that this embodied framing can complement conventional analytic views by strengthening qualitative intuition \cite{Lee2021DataVisceralization}. For BioMedVis, the direct implication is that visceral scale can become a first class analytic channel: for example, representing cellular crowding, spatial sampling density, or anatomical extent in ways that leverage the user’s everyday spatial priors, instead of forcing everything through plots that flatten scale into pixels.

A second step beyond purely visual immersion is to restore some sense of \emph{touch} and physical resistance. Full haptic hardware is still expensive and difficult to deploy, especially for multi user settings, but XR can sometimes exploit \emph{pseudo haptics}, where vision dominates perception and carefully designed visual feedback creates the illusion of haptic properties. Weiss et al.\ study \emph{haptic illusions} in co located collaborative VR by independently manipulating the apparent shape and size of a shared object during a handover task \cite{Weiss2025HapticIllusions}. Their results show both the promise and the risk of pseudo haptics: users adapt their strategies to the illusion, but visuo haptic mismatches can degrade performance and subjective experience, and asymmetric roles can amplify these effects \cite{Weiss2025HapticIllusions}. For life science analytics, this matters because collaboration is often the norm: teams jointly interpret cohorts, structures, and experimental evidence. If XR systems attempt to ``add touch'' through visual dominance, they must do so conservatively, maintaining consistency across users and avoiding manipulations that create confusion or mistrust during shared interpretation \cite{Weiss2025HapticIllusions}.

Finally, embodied understanding does not have to remain inside an XR device. \emph{Data physicalization} goes one step further by turning data into a tangible artifact that can be handled, shared, and discussed without headsets. Protein ORIGAMI demonstrates this move in a pragmatic way: it is a browser based tool that converts peptide sequences into printable templates for folded paper models (for example, helices and strands), with residue properties encoded through color and geometry \cite{Reisser2018ProteinORIGAMI}. The contribution is not computational novelty in analysis, but a reminder that the ultimate ``display'' for some tasks is a lightweight physical object that supports tactile inspection, face to face discussion, and teaching without any tracking or rendering constraints \cite{Reisser2018ProteinORIGAMI}. In the context of this STAR, physicalization and visceralization broaden the interface argument: immersive assistance is not only about better menus or faster selection, but about choosing representations that align with the body’s perceptual strengths, including scale perception, spatial intuition, and, when appropriate, touch.

% \subsection{Cross-Modal Synergies and Tensions}
%  Discuss how combining certain modalities with certain AI modes yields benefits or challenges (e.g., 2D + conversational for accessibility, large display + adaptive for collaboration, VR + immersive-AI for navigation). Emphasize unexplored modality–AI combinations as opportunities.
%  (Transition: argue that as data complexity grows, AI assistance is becoming essential, leading into evaluation considerations in Section~6.)

\subsection{Cross-Modal Synergies and Tensions}
\label{sec:cross-modal-synergies}

Across the surveyed literature, the strongest systems rarely rely on a single modality or a single assistance mechanism. Instead, they pair modalities with assistance types that compensate for known bottlenecks. Desktop interfaces remain unmatched for precise control, reproducible parameter setting, and integration with scripting workflows, and they become substantially more accessible when paired with conversational or intent-based interaction that reduces configuration friction and lowers the barrier for non-experts. Large displays and co-located environments amplify group sensemaking, but they are limited by shared reference problems and coordination overhead, which makes them natural candidates for adaptive and attention-oriented assistance that maintains alignment, manages view placement, and supports personal overlays without breaking the shared context, as demonstrated by hybrid wall plus AR designs~\cite{Reipschlaeger2021PersonalAR} and by collaborative immersive workspaces that externalize and spatially distribute analytic artifacts~\cite{Lee2021SharedSurfacesSpaces}. In immersive VR and AR, where the stereo dividend can improve perception but navigation and selection are costly, immersive-AI assistance becomes a necessity rather than a convenience, for example by guiding viewpoint between exocentric overview and egocentric inspection~\cite{Ng2024ExoEgo}, steering users through dense geometry~\cite{Alharbi2023Nanotilus}, stabilizing precise interaction at room scale~\cite{Dai2025MagicPortals}, and directing attention to relevant targets in a 360 degree workspace~\cite{Doerr2024SituatedHighlighting}. These examples suggest that modality and assistance should be designed as a coupled system, not as independent add-ons.

At the same time, cross-modal combinations introduce tensions that are easy to overlook if each component is evaluated in isolation. First, collaboration can fracture when assistance is personalized, if users receive different overlays, recommendations, or highlights, the system can unintentionally widen the referential gap that already challenges shared analysis~\cite{Pettersson2009VisualReferences}. Second, adaptive and conversational assistance can threaten reproducibility when the system state changes based on prior interactions, or when explanations are generated rather than strictly derived from traceable computations. Third, cross-device ecosystems raise engineering and provenance burdens, because synchronizing views, selections, and algorithmic stages across browsers, desktops, and headsets requires explicit workflow and state management, a point emphasized by web-based and pipeline-oriented architectures~\cite{CortesRodriguez2024MolecularWebXR,Borowski2025DashSpace,Jeon2025XROps}. These synergies and tensions also highlight opportunity areas that remain under-explored, for example conversational guidance that is tightly integrated with immersive navigation to reduce the navigation tax, adaptive assistance that explicitly optimizes joint attention in co-located collaboration, and workflow-level systems that treat multiresolution abstraction and streaming as first-class assistance rather than an implementation detail. As biological data complexity and heterogeneity continue to grow, these cross-modal, mixed-initiative designs will become increasingly necessary, which motivates the evaluation focus of Section~\ref{sec:eval-landscape}, where we discuss how to measure not only whether AI assistance works, but whether it improves scientific reasoning without compromising trust, provenance, or collaboration.


% \section{Evaluation Landscape}
% When reviewing visualizations, it is important to consider both how effectively they support analytical tasks and how well they align with users’ cognitive processes. Isenberg et al \cite{Isenberg2013ReviewEvaluatingVis} highlight that visualization evaluation should go beyond surface‐level usability metrics to examine how design choices influence interpretation, bias, and decision quality.


% \subsection{Evaluation Across Visualization Modalities}
%  Discuss evaluation methods for different modalities.
\section{Evaluation Landscape}
\label{sec:eval-landscape}

When reviewing visualizations, it is important to consider both how effectively they support analytical tasks and how well they align with users’ cognitive processes. Isenberg et al.~\cite{Isenberg2013ReviewEvaluatingVis} emphasize that evaluation should go beyond surface level usability metrics to examine how design choices influence interpretation, bias, and decision quality.

\subsection{Evaluation Across Visualization Modalities}
\label{sec:eval-across-modalities}

A recurring pitfall in evaluating immersive systems is treating the comparison as a binary choice: either a conventional 2D desktop view or a headset based 3D view. In practice, there is an important middle ground. Desktop systems can already capture some of the benefits often attributed to immersion by adding depth cues and controlled 3D interaction on a flat display. This creates a useful baseline for evaluation: if a headset system claims an advantage, it should ideally outperform not only 2D scatterplots, but also strong desktop designs that include shading, depth cues, and rotation.

This is especially relevant for life science workflows, where many “high dimensional” datasets (for example cell embeddings or multi feature cohort representations) are explored through low dimensional projections. The evaluation question is not only whether VR or AR helps, but whether the benefit comes from immersion itself, or from more basic factors such as increased depth cues, motion based viewing, and better separation of overlapping structures.

\subsubsection{2D Desktop and Pseudo 3D Evaluation}
\label{sec:eval-2d-pseudo3d}

A common argument in visualization is that 2D is the safer default: it avoids occlusion, is easier to interact with, and supports fast selection and annotation. However, several studies show that adding carefully designed 3D cues on the desktop can materially improve cluster perception and group separation, even without a headset. This “2.5D” compromise uses 3D only where it buys clarity, while keeping interaction costs closer to standard desktop analytics.

Wang and Mueller challenge the assumption that 3D is automatically harmful for visual cluster analysis by showing how a shaded 3D rendering can make cluster structure more legible on a conventional display~\cite{WangMueller2014Does3D}. Their core point is pragmatic: rotation plus shading can expose the shape of dense point clouds and reduce apparent overlap because users can look “around” structures rather than interpreting a single flattened view. They also note that an important depth cue is motion parallax, meaning depth is inferred from how points move relative to each other as the viewpoint rotates. In other words, some of the perceptual benefit often credited to immersive displays can start with a mouse driven, rotatable, shaded 3D projection on the desktop.

Poco et al. provide quantitative and user study evidence for this middle ground~\cite{Poco2011Framework3DProjections}. They compare 2D versus 3D multidimensional projections shown on a standard screen and report that neighborhood based similarity metrics support higher precision for 3D projections. In their user study, certain analysis tasks are answered more reliably and confidently in 3D, although the 3D condition can take longer due to interaction overhead. This tradeoff is directly relevant for evaluation: when 3D helps, it may improve correctness or confidence, but it can also impose extra navigation cost. A fair evaluation therefore should report accuracy, time, and confidence together, rather than time alone.

Moreover, Alper et al. demonstrate a complementary “pseudo 3D” strategy for graphs: keep the layout in 2D, but use stereoscopic depth only as a highlighting channel~\cite{Alper2011StereoscopicHighlighting}. This is a concrete example of the 2.5D compromise: depth is not used to encode the entire structure, but to separate a selected subset from the background. Their results indicate that combining stereoscopic depth cues with conventional static highlighting improves performance, and that a full 3D layout does not necessarily outperform a strong 2D baseline with effective highlighting. For life science networks and embeddings, this suggests that careful use of depth for emphasis (rather than full 3D relocation of all geometry) can be a competitive baseline that immersive systems must beat.

Considered as a whole, these findings motivate a simple evaluation principle for Hairballs to Hypotheses: the “immersive advantage” does not begin when a headset is worn. It begins when a system introduces additional separation cues, such as shading, controlled 3D rotation, or depth based highlighting. Headset based systems should therefore be evaluated against both 2D and pseudo 3D desktop baselines to isolate what immersion uniquely contributes beyond improved depth cues.



% \subsubsection{Large-Display Evaluation}
%  How large collaborative displays are evaluated (e.g., group performance, situational awareness), noting the scarcity of standardized studies.
\subsubsection{Large-Display and Collaborative Evaluation}
\label{sec:eval-large-collab}

Large-display visualization is often evaluated with familiar individual metrics (time, error, workload). However, once a visualization becomes a \emph{shared reference} for a co-located team, a different bottleneck dominates: whether collaborators can efficiently establish and maintain \emph{joint attention}---confidence that they are talking about the same visual object at the same time. Pettersson et al.\ describe this as a problem of \emph{shared visual references}: when users cannot easily verify that their partner is referencing the same item, collaboration remains possible but becomes less efficient, because the team must spend extra effort on grounding, clarification, and deictic repair (e.g., repeated pointing and verbal confirmation) rather than analysis~\cite{Pettersson2009VisualReferences}.

This cost is quantified in Pettersson et al.'s empirical comparison of integrated views versus partitioned views that reduce clutter but remove mutually shared visual references. Even when the collaborative task required only a minimal shared basis for comparison, the condition with reduced shared references was significantly less efficient, while error remained low; the main effect was a shift from visual verification to communication-heavy coordination~\cite{Pettersson2009VisualReferences}. This result motivates an evaluation stance for large collaborative displays: the limiting factor is often not rendering speed or pixel count, but the \emph{referential gap}---the time and interaction overhead required for collaborators to reach common ground about what is being referenced. Practically, large-display evaluation should therefore include collaboration-centric measures such as (i) time-to-ground a reference, (ii) frequency of clarification questions, (iii) rate of deictic gestures (pointing, gaze following), and (iv) conversational breakdowns or repair strategies, in addition to classic time and error.

Immersive, free-movement environments suggest one pathway to mitigate this gap by making reference acts more legible. The FIESTA system (``Shared Surfaces and Spaces'') explicitly supports embodied deixis by rendering tracked head and hand avatars aligned to users' real positions, enabling pointing gestures and conveying gaze direction~\cite{Lee2021SharedSurfacesSpaces}. Because participants can freely roam, approach a target, and point from a similar vantage, the workspace behaves more like an in-person whiteboard discussion than a static wall display. FIESTA also makes interaction state broadly visible (e.g., shared selections and pointers), which can reduce ambiguity about what is currently under discussion and therefore supports workspace awareness~\cite{Lee2021SharedSurfacesSpaces}. Evaluating such systems should therefore test not only whether teams finish faster, but whether the environment reduces referential overhead, for example by decreasing the number of repeated pointing episodes or the need for verbal disambiguation.

Hybrid large-display designs further underscore that ``shared reference'' is not only about pointing, but also about minimizing mutual interference while preserving shared context. Reipschlager et al.\ argue that large displays are challenging for effective multi-user support and managing data density, and propose augmenting a shared wall with \emph{personal} AR overlays so individuals can access extra views and details without cluttering the shared surface or obstructing collaborators~\cite{Reipschlaeger2021PersonalAR}. From an evaluation standpoint, this suggests that large-display studies should measure not only team performance, but also how well the system balances shared context with individual exploration, including metrics for distraction, occlusion, and perceived coordination quality.

In summary, the central evaluation lesson for large collaborative displays is that a shared visual workspace introduces a new cost function: the cost of maintaining shared reference. Systems can reduce this cost through interaction techniques that make pointing and gaze legible, through free-movement collaboration, or through hybrid personal overlays. Consequently, collaboration-focused metrics should be treated as first-class outcomes rather than secondary observations.

\subsubsection{Immersive Environments (VR and AR) Evaluation}
\label{sec:eval-immersive}
% \textit{Immersive evaluation needs to quantify a tradeoff. Stereoscopic depth can make dense 3D structures more legible, but embodied navigation and display physiology introduce new costs that can dominate time and comfort.}

A useful way to frame evaluation in immersive environments is to separate two competing effects. The first is a \emph{stereo dividend}, a measurable perceptual benefit from true binocular disparity, head coupled motion parallax, and embodied scale. The second is a \emph{navigation tax}, the time, workload, and fatigue incurred by moving through and operating in 3D rather than manipulating a view with a mouse.

\paragraph{The stereo dividend: monoscopic 3D is not the same as stereoscopic 3D.}
Monoscopic 3D, typical of a desktop 3D view, renders a 3D layout but shows the same image to both eyes, depth is inferred from perspective, shading, and motion. Stereoscopic 3D, typical of VR and many AR head mounted displays, renders distinct left and right eye images, enabling binocular disparity and stronger occlusion ordering. In graph analytics tasks, Greffard et al.\ compared 2D, monoscopic 3D, and stereoscopic 3D, and found that the stereoscopic condition produced significantly higher accuracy than both alternatives for community detection, even though 2D yielded lower response times \cite{Greffard2014BeyondMonoscopic3D}. Ware and Mitchell report a complementary result for path tracing in node link diagrams, with stereo and motion depth cues allowing users to trace short paths in graphs containing hundreds to a thousand nodes with low error, an order of magnitude larger than comparable 2D viewing \cite{Ware2008Graphs3D}. For point cloud tasks, which are closer to biomedical embeddings than node link graphs, Kraus et al.\ show that increased immersion can be a substantial benefit for cluster identification in 3D data \cite{Kraus2020ImmersionClusterIdentification}. Taken together, these findings motivate an evaluation stance where VR and AR are not treated as aesthetic upgrades, they are tested as perception altering interfaces that can change error rates on tasks where occlusion and depth are core to the problem.

\paragraph{The navigation tax: perception improves, locomotion still costs.}
The stereo dividend does not come for free, because immersive systems shift some of the analytical burden from purely visual decoding to viewpoint management. Yang et al.\ explicitly analyze embodied navigation for immersive abstract visualization, decomposing navigation into travel and wayfinding costs, and showing that navigation techniques such as zooming and overview plus detail can be more effective than locomotion alone for 3D scatterplots, especially in seated VR \cite{Yang2021EmbodiedNavigation}. Their discussion also highlights practical costs that matter for evaluation, larger tracked spaces can support more physical navigation, but can also induce significant fatigue, and switching between physical movement and pointer based teleportation can introduce context switching overhead \cite{Yang2021EmbodiedNavigation}. For evaluation methodology, this implies that time and error are necessary but incomplete, immersive studies should also report navigation specific metrics (travel distance, number of viewpoint changes, reorientation events) and subjective workload, since these capture the operational cost of making use of depth.

\paragraph{Physiology and artifacts: the ugly side of stereo.}
Even when stereoscopy improves accuracy, it can also produce discomfort and visual artifacts. McIntire and Liggett summarize how vergence accommodation mismatch, crosstalk, and related display limitations contribute to eyestrain and fatigue in stereoscopic viewing, and they note that a nontrivial fraction of users can experience discomfort \cite{Sedlmair2014GoodBadUgly}. This is not an argument against immersive analytics, but it is a strong argument for reporting comfort outcomes alongside performance outcomes, including simulator sickness measures, dropouts, breaks, and hardware parameters that affect stereo quality.

\paragraph{Strategic conclusion: 3D is here to stay, so evaluate it honestly.}
Brath’s position, that 3D infovis is here to stay and the field should focus on where it is useful and how to handle its limitations, provides a pragmatic endpoint for evaluation framing \cite{Brath2014InfoVisHereToStay}. For life science visual analytics, many targets are intrinsically spatial, from molecular assemblies to tissue scale morphology and anatomical connectomes, so depth perception is often a necessary ingredient for untangling dense configurations. The evaluation agenda is therefore not to claim that VR is universally superior, but to quantify when the stereo dividend outweighs the navigation and physiological taxes, and to use those measurements to justify hybrid workflows that move fluidly between immersive and non immersive tools.

\subsection{Evaluation of AI-Assistance Modes}
\label{sec:eval-ai-modes}
% \textit{Discuss how each AI assistance type is evaluated in the context of visual analytics.}

Section~\ref{sec:eval-across-modalities} emphasized that visualization \emph{modality} changes task load and cognitive strategy, for example, immersive depth can improve spatial judgments while increasing navigation burden. This section shifts the focus from \emph{where} analysis happens to \emph{how} computational intelligence changes the analytic loop. Evaluating AI assistance is not the same as evaluating a visualization technique in isolation. Assistance can alter which views users see, which operations are executed, which explanations are offered, and which hypotheses appear salient. In life-science contexts, where analytical outcomes can influence downstream experimental decisions, evaluation must therefore address not only performance and usability, but also scientific reliability, interpretive bias, and the user’s ability to supervise and correct the system~\cite{Isenberg2013ReviewEvaluatingVis}.

A practical starting point is to treat AI assistance as an intervention and to evaluate it with ablations, comparing (1) the same interface with and without the assistance component, and (2) competing assistance strategies under the same task conditions. This controls for modality and interface confounds, and it makes the value added by assistance measurable. Importantly, the dependent variables should be chosen to match the task category being supported (Section~\ref{sec:task-categories}). For Navigation and Multiscale Orientation, evaluation should include orientation loss, reorientation events, and interaction effort, not only completion time. For Comparison and Differentiation, it should include error rates, stability across parameter changes, and whether users can verify differences. For Selection and Precision Interaction, it should include target acquisition accuracy and the cost of recovery from errors. For Sensemaking and Hypothesis Development, it should include whether users can articulate evidence, track provenance, and detect when the system’s reasoning is flawed. For Coordination and Collaborative Reasoning, it should include measures of common ground and referential clarity rather than only individual speed.

Across assistance types, we found three cross-cutting evaluation questions that repeatedly determine whether AI helps or silently harms. First, \emph{effectiveness}, does the assistance improve task outcomes, reduce interaction burden, or enable tasks that would otherwise be infeasible at realistic data scales. Second, \emph{process quality}, can users understand what the system did, why it did it, and how to reproduce or audit the result. Third, \emph{control and calibration}, do users remain appropriately skeptical and able to intervene, or does the assistance induce overreliance, automation bias, or unearned confidence.

Evaluation practices are organized in the subsections below according to the four assistance modes used throughout the STAR. \emph{Algorithmic assistance} is often evaluated with computational and structural metrics, yet it must also be judged by its impact on interactive feasibility and representational trade-offs. \emph{Adaptive assistance} requires evaluation of intent inference and interaction reduction, but it also raises questions about stability over time, user surprise, and reproducibility. \emph{Conversational and agentic assistance} introduces evaluation challenges around scientific correctness, controllability, and transparency, because errors can propagate into analytic decisions rather than remaining localized to a single view. Finally, \emph{immersive-AI assistance} requires metrics that combine perceptual and embodied factors, navigation efficiency, selection precision, comfort, and fatigue, because the assistance is embedded directly in interaction and viewpoint control.

In short, evaluation of AI assistance in life-science visual analytics must be task grounded, ablation driven, and process aware. Without these elements, it is easy to report impressive capabilities while failing to measure whether the assistance actually improves scientific reasoning, or merely changes the path users take to reach conclusions.

\subsubsection{Algorithmic Assistance}
 %Metrics for algorithmic techniques (clustering quality, layout metrics, etc.) and note that these often ignore human-in-the-loop impact.
\label{sec:eval-alg-assistance}

 Evaluation of algorithmic assistance in life-science visual analytics must account for the fact that time, complexity, and latency are usability features, not merely performance concerns. As biological datasets grow in size and density, algorithmic choices increasingly determine which analytical tasks (Section~\ref{sec:task-categories}) are feasible at all. We therefore frame evaluation around three tightly coupled axes: computational scalability, representational fidelity, and auditability/provenance.

\paragraph{Computational scalability and interaction latency}
    
The first evaluation axis concerns how algorithmic methods scale with data size and how this scaling impacts interactive responsiveness. Classical force-directed graph layouts provide a useful baseline: methods such as ForceAtlas2 remain effective for moderate graph sizes but exhibit quadratic or worse behavior as node and edge counts grow, leading to unacceptable latency and interaction breakdowns in dense biological networks \cite{Jacomy2014ForceAtlas2}. Work on faster force-directed graph drawing using well-separated pair decomposition (WSPD) makes this limitation explicit by demonstrating how algorithmic complexity, rather than rendering alone, becomes the dominant bottleneck at scale \cite{Gansner2015WSPD}.
Recent systems emphasize approximation, binning, and density-based strategies as necessary responses to this compute gap. scSVA, for example, demonstrates that interactive exploration of single-cell RNA-seq data at billion-cell scale is only possible by aggregating observations into density summaries rather than rendering individual points, effectively trading raw detail for responsiveness \cite{Feng2021scSVA}. Similarly, approximate nearest-neighbor graph construction enables large-scale biological similarity analysis by replacing exact neighborhood computation with scalable approximations, making interactive workflows feasible where exact methods would fail \cite{Xu2023ANNBio}.
From a task perspective, scalability failures disproportionately damage Navigation and Multiscale Orientation and Comparison and Differentiation tasks (Section \ref{sec:task-categories}: when interaction latency exceeds cognitive tolerance, users can no longer maintain spatial or conceptual context while exploring structure.
    
\paragraph{Representational fidelity under complexity management}
The second axis evaluates what algorithmic assistance preserves, removes, or distorts when managing complexity. Decluttering techniques such as edge bundling illustrate the long-standing tension between readability and computational cost: while bundling can reduce visual clutter in dense graphs, it introduces additional computation and may obscure individual paths, limiting its effectiveness as graph size grows \cite{Holten2006EdgeBundling}.
More recent work explicitly treats complexity management as a design space rather than an afterthought. CMGV provides a unified framework that categorizes complexity-management strategies—aggregation, filtering, abstraction, and approximation—and emphasizes that each strategy entails specific representational trade-offs \cite{Keller2023CMGV}. These trade-offs must be evaluated relative to analytic intent: what is gained in overview may be lost in precision, and vice versa.
Practical desktop systems further ground these concerns. Graphia demonstrates how performance-aware design choices shape interaction expectations in real analytical workflows, balancing graph size, layout recomputation, and responsiveness to support iterative exploration of high-dimensional biological data \cite{Freeman2021Graphia}. In these systems, representational fidelity is inseparable from performance constraints: what is shown is determined by what can be computed fast enough to remain interactive.
    % \subsubsection{Algorithmic Assistance}

\paragraph{Procedural provenance is part of evaluation, not an afterthought.}
Algorithmic assistance is evaluated not only by mathematical fidelity (e.g., stability, topology preservation, neighborhood recall) but also by procedural legitimacy. Even a visually compelling embedding or projection is not safe to treat as analytic ground truth if authorship, reproducibility, or provenance is in doubt. The retraction of Panoramic Manifold Projection (Panoramap) on authorship and provenance grounds is a useful cautionary example. It underscores that verification is both mathematical and procedural, and that evaluation reports should include reproducibility artifacts, implementation traceability, and clear provenance statements, especially when an algorithm becomes a widely reused preprocessing step \cite{ijms2024retraction,wang2022panoramap_retracted}.

\paragraph{Auditability, provenance, and system-level pressure}
The third axis concerns whether users can understand and reason about what algorithmic assistance has done. As systems increasingly rely on approximation, aggregation, and precomputation, evaluation must consider whether analysts can trace how results were produced and assess their reliability.
System-level studies make this pressure visible. Interactive Graph Visualization and Teaming Recommendation in an Interdisciplinary Project’s Talent Knowledge Graph illustrates how latency and scaling constraints directly affect collaborative analysis, forcing systems to prioritize responsiveness over completeness in order to remain usable \cite{Zhang2024TalentKG}. Similarly, Uchimata highlights how web-based visualization of large 3D genome structures must negotiate strict performance budgets, demonstrating that deployment context (desktop vs. web) is itself an evaluation factor that shapes algorithmic choices and analytic affordances \cite{Kobayashi2023Uchimata}.
Across these examples, auditability is not only about algorithm transparency but also about exposing limits: users must be able to recognize when approximation, aggregation, or pruning has altered the analytical substrate.


Overall, these works show that evaluation of algorithmic assistance cannot be reduced to accuracy or visual quality alone. Computational scalability, representational fidelity, and auditability/provenance form an inseparable triad that determines whether algorithmic assistance genuinely supports life-science visual analytics or silently constrains it. As dataset size increases, failures along any of these axes first undermine navigation and comparison tasks, reinforcing the need to treat complexity management as a first-class evaluation concern rather than an implementation detail
 
\subsubsection{Adaptive Assistance}

Evaluating adaptive assistance requires separating system-level performance from its downstream effects on analysis behavior and user experience.
\emph{Performance metrics} capture the efficiency and fidelity of the adaptive machinery itself, including interaction latency, computational overhead, and prediction accuracy of user models such as next-interaction or intent prediction and exploration-bias detection.
\emph{Behavioral outcomes} assess how adaptation reshapes analytic activity, using measures such as coverage and diversity of the explored space, balance across attributes or hypotheses, and the system’s ability to detect, and ideally, mitigate rather than reinforce, exploration bias~\cite{Ha2022UserModeling}.
\emph{Human factors} evaluation addresses experiential consequences of mixed-initiative guidance, including trust, perceived autonomy and controllability, and cognitive load, reflecting concerns that adaptive systems may reduce burden while simultaneously steering analysis.
Finally, evaluation must be \emph{audience-dependent}: expert analysts and public or novice users respond differently to guidance, with experts often prioritizing transparency and override, and non-experts benefiting more from prescriptive support.
Dual expert/end-user evaluation frameworks demonstrate that adaptive guidance should therefore be assessed separately across user populations, using task-appropriate success criteria rather than a single aggregate metric~\cite{Steichen2017DualEvaluation}.
Adaptive systems should communicate a balanced view of their impact by reporting both benefits (such as efficiency gains or reduced cognitive load) and harms (such as steering effects or reduced diversity of exploration). For each side, system designers should provide at least one explicit, well-defined metric to support these claims.

\subsubsection{Evaluation of Conversational and Agentic Assistance}
% \subsubsection{Conversational Assistance}
\label{sec:conversational-assistance}
% \textit{ How to evaluate LLM-driven analytics (checking for factual correctness, task success rates, user trust and understanding), noting the challenge of scientific accuracy.}
%\subsubsection{Conversational Assistance}

Evaluating conversational and agentic analytics systems requires a different perspective than evaluating traditional visualization tools. In life-science research, analytic errors do not remain confined to the interface: decisions made during analysis directly influence experimental design, resource allocation, and biological interpretation. Choosing the wrong comparison, filtering data incorrectly, or following an inappropriate analytic path can lead to wasted reagents, misdirected experiments, or incorrect conclusions, even if intermediate outputs appear reasonable. These concerns map directly onto Process Awareness and Provenance and Query Refinement tasks defined in Section~\ref{sec:task-categories}, where understanding and revising analytic steps is central to scientific reliability.



Early evaluations of natural language interfaces (NLIs) for visualization primarily focused on whether systems produced correct outputs in response to user queries, such as generating an appropriate chart or applying a requested filter \cite{Wang2024DomainBridge}. These criteria are appropriate when interaction is limited to isolated requests. However, as discussed in Section~\ref{sec:agentic-orchestration}, newer systems increasingly plan and execute multi-step analyses on the user’s behalf \cite{Jia2024LightVA,Kim2024PhenoAssistant}. In this setting, correctness of the final result is not sufficient. Evaluation must also address whether the system chose reasonable intermediate steps, whether those steps align with the user’s intent, and whether users can intervene when something goes wrong.



One important evaluation requirement is reasoning transparency. DeepVIS demonstrates how exposing intermediate reasoning steps, such as how a question was interpreted, which data were selected, and why a particular visualization was chosen, allows users to inspect and verify system behavior \cite{DeepVIS2023}. In life-science analysis, this visibility is essential. Without it, users cannot determine whether results reflect meaningful biological structure or arise from inappropriate assumptions, data transformations, or visual encodings. Systems that hide their reasoning make it difficult for scientists to assess validity or correct errors before they propagate downstream.



Human-in-the-loop workflows further illustrate how evaluation must account for domain grounding and oversight. Wang et al.\ show that when analyzing large collections of life-science literature, reliable use of LLMs depends on explicitly structuring human validation at key abstraction points \cite{Wang2024DomainBridge}. Rather than relying on end-to-end automation, their approach translates specialized biological terminology into standardized data and task representations that experts can review and correct. This design reflects an implicit evaluation criterion: success is measured by faithful translation and interpretability, not by autonomy alone.



As analytics systems become more agentic, evaluation must also address failure modes unique to autonomous behavior. Systems that plan and act can fail in ways that are subtle and difficult to detect, such as selecting inappropriate subsets of data, applying unsuitable analysis methods, or making premature recommendations \cite{Chen2024ProactiveVA}. These failures may not immediately produce incorrect-looking results, but can steer users toward flawed interpretations. Effective evaluation therefore requires assessing whether users can recognize these failures, understand why they occurred, and recover by redirecting or correcting the analysis—capabilities closely tied to core task requirements in Section~\ref{sec:task-categories}.



Finally, the interaction contexts discussed in Sections \ref{sec:large-displays} and \ref{sec:spatial-graph-reasoning} introduce additional evaluation considerations. On large displays and in immersive environments, analysis is often supervised collaboratively, with teams relying on shared visual context, speech, and spatial cues to maintain awareness and alignment. In these settings, evaluation should consider not only individual task performance, but also how well systems support collective oversight, shared understanding, and timely intervention \cite{Leon2025TalkToTheWall,Song2025EmbodiedNLI,Jia2025VOICE}.



In sum, these considerations suggest that evaluating conversational and agentic assistance in visual analytics requires a shift from outcome-focused metrics toward process-focused evaluation. For life-science applications in particular, trustworthy systems must make their reasoning visible, support meaningful human oversight, and preserve domain integrity throughout the analytic workflow. As systems take on greater responsibility for procedural tasks, evaluation frameworks must evolve to ensure that increased autonomy enhances, rather than undermines, scientific reliability.

\subsubsection{Immersive-AI Assistance}
\label{sec:eval-immersive-ai-assistance}
% \textit{How immersive intelligent features are evaluated (navigation efficiency, selection accuracy, user comfort), noting that this area is nascent with few established protocols.}

Evaluating immersive AI assistance is challenging because the assistance is rarely a detachable component. In XR, ``intelligence'' is often embedded directly into viewpoint control, selection mechanics, occlusion management, and multimodal input fusion, so the evaluation must capture both the analytic outcome and the embodied cost of reaching it. In other words, immersive systems can deliver a perceptual dividend through depth and scale, but they also impose operational taxes through locomotion, disorientation, and mid air interaction fatigue. Immersive AI assistance should therefore be evaluated as a \emph{performance and comfort mediator}, it is successful when it reduces navigation burden, stabilizes interaction, and guides attention without masking uncertainty or taking control away from the analyst.

\paragraph{Navigation efficiency and viewpoint management.}
Navigation is the dominant hidden cost in immersive analytics, especially for abstract or semi abstract biological views (embeddings, similarity spaces, networks). Yang et al.\ decompose embodied navigation into travel and wayfinding costs, and show that interaction designs that reduce unnecessary locomotion, for example zooming and overview plus detail, can outperform locomotion alone in 3D scatterplot analysis \cite{Yang2021EmbodiedNavigation}. This motivates navigation focused evaluation metrics that go beyond time and error, including travel distance, number of viewpoint changes, reorientation events, collisions or near collisions, and the frequency of context rebuilding after a viewpoint shift. When navigation becomes AI mediated, these metrics must be paired with measures of \emph{appropriateness}, for example whether automatic transitions match the user’s analytic intent. Ng et al.\ provide a useful baseline by comparing exocentric and egocentric frames for biomedical cohort analysis in VR, showing that view framing changes both speed and perceived usability \cite{Ng2024ExoEgo}. For systems that generate or recommend routes through dense geometry, such as Nanotilus, evaluation can additionally include path quality measures, for example whether the camera route avoids occluders and maintains a stable mental map, and whether users can interrupt or deviate without losing orientation \cite{Alharbi2023Nanotilus}.

\paragraph{Selection and manipulation accuracy under motor and physics constraints.}
A second evaluation axis concerns whether immersive AI assistance improves precision in dense biological scenes where standard controller based ray casting becomes jittery and exhausting. Dai et al.\ evaluate this problem through Magic Portals, a focus plus context technique that brings distant regions into comfortable reach, optionally with haptic confirmation, and can be assessed with target acquisition accuracy, selection time, correction actions, and self reported workload and arm fatigue, often called the gorilla arm effect, which is the strain that builds when users hold their arms elevated for prolonged mid air interaction \cite{Dai2025MagicPortals}. Molecular interaction tasks highlight a related idea, constraints matter as much as freedom. In immersive docking, Mishra et al.\ show that human guided manipulation within physically meaningful constraints can produce useful interaction trajectories that feed subsequent simulation, suggesting evaluation should consider both user performance and downstream scientific utility, for example whether assisted interaction produces plausible, reproducible docking or unbinding pathways, not only whether the user could ``grab and move'' objects quickly \cite{Mishra2024DockingVR}.

\paragraph{Attention guidance, cognitive load, and user comfort.}
Finally, immersive assistance often operates as attention management in a 360 degree workspace, where relevant targets can be out of view and where spatial cues compete with task cognition. Doerr et al.\ empirically evaluate highlighting techniques for situated brushing and linking, illustrating how attention cues can improve findability and reduce search effort, but can also become clutter when selections grow, which suggests that evaluation should explicitly track both benefits (find time, misses, reacquisition time) and side effects (visual overload, distraction, perceived loss of agency) \cite{Doerr2024SituatedHighlighting}. Related training evidence reinforces that guidance can change user strategies in lasting ways. In SONAR interpretation training, an egocentric conformal overlay improved speed and accuracy, but it also raised concerns about over reliance once assistance is removed, a pattern that immersive AI evaluation should measure directly through retention and transfer tests \cite{Salamon2025TrainingSONAR}. Across all immersive AI studies, performance results should be reported alongside comfort outcomes, including simulator sickness measures, breaks, dropouts, and hardware parameters that affect stereo quality, because an assistance technique that improves accuracy is not viable if it increases fatigue or discomfort to the point that users avoid sustained use.

Overall, evaluation practice for immersive AI assistance is still nascent. The strongest studies treat assistance as an intervention, compare it against non assisted baselines, log multimodal interaction traces, and report navigation and comfort measures in addition to task accuracy. However, consistent protocols and benchmarks remain rare, which limits comparability across systems and makes it difficult to generalize results beyond a single interface or dataset.

\subsection{Gaps in Evaluation}
\label{sec:gaps-evaluation}
% \textit{Major unmet evaluation needs: missing benchmark tasks and datasets, lack of cross modality studies, and insufficient methods for combined AI plus immersive interaction evaluation.}

The literature reveals three evaluation gaps that repeatedly slow progress, even when technical innovation is strong. First, there is a lack of shared standards and benchmark tasks for multimodal, AI assisted visual analytics, especially in life science settings where realistic data complexity is central. Many studies rely on custom datasets, bespoke tasks, and one off logging schemes, which makes it hard to compare results or to reproduce findings across labs. The unified task categories in Section~\ref{sec:task-categories} can serve as a basis for benchmark design, but the community still needs reference datasets, task scripts, and reporting templates that cover multimodal inputs (gaze, gesture, speech, controller), mixed initiative behavior, and long running analytic sessions.

Second, cross modality comparisons remain the exception rather than the rule. Many papers evaluate a single modality in isolation, so they cannot answer the practical question that life science teams face, when should a workflow stay on the desktop, when should it move to a large display, and when is immersion worth the overhead. The field needs more controlled studies that run the \emph{same} tasks on the \emph{same} data across 2D, pseudo 3D, large displays, and VR or AR, reporting both task performance and operational costs (navigation effort, fatigue, coordination overhead). Without these comparisons, it is easy to attribute gains to immersion that are actually due to different encodings, or to attribute failures to VR that are actually due to poor layout or interaction design.

Third, there are insufficient methods to evaluate coupled AI and immersive interactions. When assistance is adaptive, intent inferred, or viewpoint controlling, the system becomes a dynamic policy rather than a static tool. Standard time and error measures do not capture whether assistance steers analysis, whether users can detect failures, or whether they can recover without losing scientific provenance. Addressing this requires evaluation frameworks that combine ablations (assistance on versus off), process measures (interaction traces, decision points, provenance awareness), and comfort measures, and that explicitly test both short term performance and longer term calibration, including over reliance and transfer of learning. These gaps motivate the need for new evaluation frameworks that treat multimodal XR analytics as mixed initiative, end to end scientific workflows, rather than as isolated interface techniques, which is a central recommendation of this STAR.


\section{Research Challenges and Opportunities}
 %Outline open research challenges revealed by this survey and opportunities for future work.
 This survey reveals that, despite significant progress in biological visual analytics, core challenges persist at the levels of analytical tasks, visualization modalities, AI assistance, and their integration. These challenges are not isolated technical gaps; rather, they reflect deeper tensions between scalability, interpretability, cognitive load, and scientific trust. In this section, we synthesize open research challenges grounded in prior work and identify opportunities for future research.
 
\subsection{Task-Level Challenges}
 %e.g., Understanding when AI assistance truly aids insight vs. hinders it (balancing automation with human control; preventing AI errors like hallucinations from misleading science).
A central task-level challenge is determining when AI assistance genuinely supports scientific insight versus when it risks misleading users. Biological visual analytics systems often accelerate early-stage exploration—such as pattern discovery or neighborhood identification—but can hinder later-stage Sensemaking and Hypothesis Development when automated outputs are accepted uncritically. Early surveys of biological network visualization already noted that visually compelling representations may obscure uncertainty or analytical assumptions, leading users to overinterpret structure in dense networks \cite{Suderman2007}.
This risk is amplified in modern systems that incorporate algorithmic abstraction or dimensionality reduction. While hierarchical and supervised methods such as Haisu provide structured embeddings that better align with biological organization, they still require users to understand what aspects of the data are emphasized or suppressed by the model \cite{vanhorn2022haisu}. Without explicit support for verification and alternative views, AI assistance may bias exploration toward dominant patterns and away from subtle but biologically meaningful signals.
More broadly, task-level evaluation remains underdeveloped. Many tools demonstrate performance improvements or visual clarity but provide limited evidence that AI assistance improves reasoning quality, error detection, or hypothesis robustness over time. As emphasized in recent surveys, understanding how visual analytics tools support end-to-end scientific workflows—rather than isolated tasks—remains an open challenge \cite{Ehlers2025}.
 
\subsection{Modality-Level Challenges}
 %e.g., Managing cognitive load in immersive setups (when is VR/AR beneficial vs. when is 2D better? Overcoming fatigue and spatial complexity).
Visualization modality fundamentally shapes cognitive and perceptual demands, yet principled guidance on when a given modality is beneficial remains limited. Desktop 2D environments dominate biological network analysis due to their precision, reproducibility, and integration with analysis pipelines, as exemplified by Cytoscape \cite{Shannon2003}. However, as network size increases, these environments suffer from severe clutter and occlusion, motivating alternative representations such as BioFabric, which replaces node–link diagrams with structured linear layouts to reduce visual overlap \cite{Longabaugh2012}.
Immersive environments promise relief from these limitations by leveraging spatial cognition and embodied navigation. Systems such as VRNetzer demonstrate that large biological networks can be explored more effectively in virtual reality, enabling users to traverse structures that would be unreadable on a flat display \cite{Pirch2021}. At the same time, immersive modalities introduce new challenges, including physical fatigue, navigation overhead, and increased cognitive load when data are highly dense or abstract. Empirical comparisons suggest that immersive benefits are task-dependent rather than universal, reinforcing the need for modality-aware design \cite{Pavlopoulos2017, Ehlers2025}.
A key open problem is identifying which task categories benefit from immersion and which are better served by conventional 2D views, as well as designing hybrid workflows that allow users to transition between modalities without losing analytical context.
 
\subsection{AI-Level Challenges}
 %\textit{Ensuring trust and interpretability in AI assistance (LLM transparency, bias in adaptive systems, preventing user over-reliance on AI). Handling hallucination and fairness issues in scientific contexts.}
At the AI level, ensuring trust, interpretability, and robustness remains a foundational challenge. As visual analytics systems increasingly incorporate machine learning models for clustering, embedding, or recommendation, users must be able to reason about how these models influence what they see. Early work already warned that network visualizations can give a false sense of certainty when algorithmic assumptions are hidden \cite{Suderman2007}.
Modern AI-assisted systems intensify this concern. Hierarchical and supervised approaches such as Haisu improve alignment with known biological structure, but they also encode domain assumptions that may not generalize across datasets or experimental contexts \cite{vanhorn2022haisu}. In immersive or interactive settings, the persuasive power of visually rich AI output further increases the risk of over-reliance, particularly when uncertainty, bias, or model limitations are not surfaced explicitly.
Recent surveys emphasize that addressing these issues requires moving beyond algorithmic accuracy toward explainability, provenance, and user-calibrated trust as first-class design goals in biological visual analytics \cite{Ehlers2025}.
 
\subsection{Integration Challenges}
 %Challenges at the intersection of modalities and AI modes.
The most significant challenges in AI-assisted biological visual analytics arise at the intersection of visualization modalities and AI assistance modes, where multiple representations, interaction techniques, and computational processes must coexist. As systems expand beyond single-mode desktop analysis, designers must coordinate algorithmic abstraction, visual encoding, and user interaction across heterogeneous environments. In immersive settings such as VRNetzer, users navigate large biological networks spatially while simultaneously engaging with algorithmically reduced or structured representations \cite{Pirch2021}. Introducing additional AI assistance, such as adaptive guidance or automated recommendations, raises unresolved questions about how control should be shared between the user and the system, how conflicting AI suggestions should be reconciled with user intuition, and how to prevent assistance from becoming intrusive or misleading in high-dimensional spatial contexts.
These integration challenges are compounded when multiple AI modes operate simultaneously. In immersive and hybrid environments, users may interact via speech, gesture, gaze, and controllers while receiving algorithmic suggestions derived from clustering, dimensionality reduction, or retrieval-based methods. Coordinating these inputs and outputs in a way that preserves user agency and analytic coherence remains largely unexplored. Without careful design, overlapping AI interventions risk overwhelming users or fragmenting attention, particularly in contexts where visually persuasive AI output may obscure uncertainty or model limitations. Prior work emphasizes that the cognitive load introduced by combining spatial navigation with algorithmic guidance can erode trust and reduce analytical effectiveness if conflicts between AI behavior and user expectations are not surfaced or resolved explicitly \cite{Pirch2021, Ehlers2025}.
A further integration challenge lies in designing multimodal analytics pipelines that span desktop, alternative representations, and immersive environments without fragmenting analytical state. Current workflows often require analysts to move between systems such as Cytoscape for annotation and filtering, BioFabric for alternative structural views, and immersive tools for large-scale exploration, with limited support for maintaining data consistency, provenance, or interaction history across these transitions \cite{Shannon2003, Longabaugh2012, Pirch2021}. As noted in recent surveys, the absence of architectures that synchronize analytical context across modalities forces users to reconstruct insight repeatedly, undermining sensemaking and reproducibility \cite{Ehlers2025}. Developing infrastructures that support seamless cross-modal transitions, shared analytical state, and consistent AI assistance remains a key opportunity for future research.


\subsection{Future Directions}
 %Highlight promising research directions.
Taken together, these challenges suggest that future progress will depend less on isolated advances in algorithms or displays and more on integrated, task-aware, and diagnostic systems. Promising directions include designing AI assistance that foregrounds uncertainty and alternatives, developing modality-aware workflows that align representation with task demands, and building infrastructures that support seamless transitions across analytical environments.
Addressing the hairball problem in the life sciences ultimately requires not only making complex data visible, but ensuring that what is seen supports trustworthy, interpretable, and scientifically grounded reasoning.
 
\subsubsection{Multimodal LLMs in Immersive Analytics}
% \textit{ AI models that can simultaneously analyze text, images, graphs, and spatial data to enable richer interactive analysis in VR/AR.}

As visual analytics systems move into three-dimensional and room-scale environments, including VR as well as wall-scale collaborative settings, interaction shifts from purely symbolic manipulation toward spatially grounded reasoning. In these contexts, users do not only issue commands; they coordinate intent through embodied actions (e.g., pointing) and spatial language that presupposes a shared layout. This is particularly consequential for life-science graph and structure exploration, where spatial organization often carries interpretive meaning (e.g., cluster separation, proximity, or structural adjacency), and where task execution frequently spans \emph{Navigation and Multiscale Orientation} and \emph{Selection, Focus, and Precision Interaction} (Section~\ref{sec:conversational-assistance}).

Empirical evidence from immersive speech interaction highlights that deictic language is not an edge case but a dominant communication strategy in spatial analysis. Song et al.\ show that, in a VR immersive analytics setting, users systematically combine utterances with embodiment cues (e.g., ``these,'' ``on the left side of me''), and that the uncertainty of speech input (semantic entropy) varies by task and phase \cite{Song2025EmbodiedNLI}. Importantly, they argue that immersive NLIs must respond to this variability through interface strategies that manage uncertainty and encourage the use of spatial cues to disambiguate targets \cite{Song2025EmbodiedNLI}. In parallel, collaborative wall-scale findings indicate that speech can be preferred for \emph{global} actions while touch is used for more localized operations, and that speech affects awareness and coordination between collaborators \cite{Leon2025TalkToTheWall}. Together, these results suggest that spatially aware reasoning interfaces should treat language, spatial context, and interaction state as co-equal components of intent resolution.

System evidence also indicates that conversational control can reduce the burden of low-level navigation mechanics when interacting with complex 3D scientific content. \emph{VOICE} operationalizes this idea for molecular exploration by translating high-level user instructions into coordinated \emph{visual} and \emph{verbal} outputs over a 3D molecular model, using prompt-engineered LLM-based processing to interpret requests and generate responses \cite{Jia2025VOICE}. While VOICE does not by itself solve general graph analytics, it illustrates an important design direction for spatially aware reasoning: users can express intent at the level of conceptual goals (what to inspect and why) while the system manages viewpoint and representation changes (how to reveal it), thereby reallocating effort from camera control to interpretation \cite{Jia2025VOICE}.

For graph-structured biological representations, spatially grounded language enables compound requests whose meaning depends simultaneously on \emph{what} is referenced and \emph{where} it is in the current spatial organization (e.g., a module ``over there'' or a neighborhood ``around this region''). Supporting such requests requires conversational systems that can (i) resolve deictic references against the live spatial state, (ii) expose disambiguation mechanisms when uncertainty is high, and (iii) preserve user agency by making intermediate interpretation steps legible. The interaction evidence above implies that these capabilities are central not only for individual exploration but also for supervision in collaborative settings, where speech is intertwined with awareness and coordination \cite{Song2025EmbodiedNLI,Leon2025TalkToTheWall}. In this sense, spatially aware graph reasoning is less about adding voice to a 3D view, and more about designing integrated intent-resolution loops in which conversational assistance is grounded in spatial context and continuously reconciled with interactive state.


\subsubsection{Spatially Aware Graph Reasoning} % Agents}
% \textit{ Intelligent agents that understand 3D spatial structure of networks (occlusion, topology) and can autonomously adjust layouts or suggest navigation in immersive environments.}
\label{sec:spatial-graph-reasoning}

As visual analytics systems move into three-dimensional and room-scale environments—including VR and wall-scale collaborative settings—interaction shifts away from menu-driven commands toward reasoning directly with spatial context. In these environments, users do not simply issue instructions to a system. Instead, they coordinate intent through a combination of speech, pointing, and shared spatial reference. This shift is especially important for life-science graph and structure exploration, where spatial organization often carries meaning—for example, when interpreting cluster separation, proximity, or structural adjacency—and where analysis commonly involves both navigating across scales and selecting precise regions of interest. These interaction patterns directly support Navigation and Multiscale Orientation and Selection, Focus, and Precision Interaction tasks defined in Section~\ref{sec:task-categories}.



Empirical studies of immersive interaction show that deictic language is not a special case, but a common and preferred way users communicate in spatial environments. Song et al.\ demonstrate that, in VR-based immersive analytics, users consistently combine spoken utterances with embodied cues such as pointing or relative position (e.g., “these,” “on the left side of me”) \cite{Song2025EmbodiedNLI}. When spatial context is available, users often omit explicit identifiers and rely on shared visual reference to complete underspecified statements. The authors further show that the uncertainty of speech input varies across tasks and phases of analysis, and argue that immersive natural language interfaces must actively manage this uncertainty by encouraging the use of spatial cues to disambiguate meaning \cite{Song2025EmbodiedNLI}. Related findings from collaborative wall-scale systems show that speech is often preferred for actions that affect the global state of an analysis, while touch is used for more localized operations, and that spoken interaction supports awareness and coordination among collaborators \cite{Leon2025TalkToTheWall}. When systems fail to correctly interpret deictic references, interaction breaks down, forcing users to over-specify commands and disrupting analytic flow.



System-level evidence further suggests that conversational interaction can reduce the burden of low-level navigation when working with complex three-dimensional scientific data. The \emph{VOICE} system illustrates this approach in molecular exploration by allowing users to express high-level requests, such as where to look or what to inspect, while the system manages camera movement, viewpoint changes, and explanatory output \cite{Jia2025VOICE}. Although VOICE does not address general graph analytics, it demonstrates an important design principle for spatially aware reasoning: users can focus on interpretation and scientific meaning while the system handles the mechanics of navigating and presenting complex spatial structures.



For graph-structured biological data, spatial language enables compound requests whose meaning depends on both what is being referenced and where it appears in the current layout (e.g., a module “over there” or a neighborhood “around this region”). Supporting these interactions requires systems that can connect spoken language to the live spatial state, clarify meaning when references are ambiguous, and show users how their requests were interpreted so they can correct misunderstandings if needed. Evidence from immersive and collaborative settings suggests that these capabilities are important not only for individual exploration, but also for supervising analysis in group settings, where speech supports shared awareness and coordination \cite{Song2025EmbodiedNLI,Leon2025TalkToTheWall}. From this perspective, spatially aware graph reasoning is less about adding voice commands to a 3D view, and more about designing interaction loops that continuously align language, spatial context, and system state.



Taken together, these findings indicate that spatial interaction is not an optional enhancement for graph reasoning systems, but a foundational requirement. By treating space, gesture, and language as integrated parts of analytic intent, immersive visual analytics environments can support more natural and effective reasoning over complex biological networks. As agentic systems take on greater responsibility for procedural aspects of analysis, spatially grounded interaction provides a critical channel through which users can guide, inspect, and control analytic behavior in domains where structure and meaning are tightly linked.



\subsubsection{Cross-Platform Visual Analytics Ecosystems}
% \textit{Unified tools that connect 2D desktop, large displays, and XR environments in one workflow, allowing analysts to seamlessly move between modalities with synchronized AI support.}
\label{sec:cross-platform-ecosystems}

A consistent theme across immersive analytics research is that no single platform effectively supports the full range of analytical activities required in real scientific workflows. While immersive environments can provide advantages for spatial reasoning, topology exploration, and embodied sensemaking, conventional 2D desktop environments remain more effective for abstract reasoning, scripting, statistical analysis, and precise parameter control. As a result, recent work increasingly frames immersive analytics not as a replacement for desktop visual analytics, but as a complementary component within broader cross-platform ecosystems.

\paragraph{The right tool for the right task.}
Hybrid-dimensional visualization research provides early empirical grounding for this perspective by demonstrating that analysts naturally alternate between 2D and 3D representations depending on task demands~\cite{SommerHybridDimVis}. Rather than collapsing all interaction into a single modality, these systems preserve the strengths of each platform by allowing abstract operations, such as filtering, configuration, and coding, to remain in 2D environments, while reserving immersive views for tasks that benefit from spatial layout, scale, and stereoscopic depth.

Collaborative immersive systems reinforce this division of labor. For example, Uplift integrates tangible and immersive tabletop interaction to support shared sensemaking and discussion, while deliberately avoiding the migration of precision-heavy or prolonged analytic work into immersive space~\cite{Ens2021Uplift}. Together, these findings suggest that effective immersive analytics systems should be embedded within heterogeneous workflows rather than treated as self-contained analytic endpoints.

\paragraph{NeuroCave and on-demand immersion.}
NeuroCave illustrates this cross-platform principle in the context of connectome topology analysis~\cite{Keiriz2017NeuroCave}. Implemented as a web-based application, NeuroCave supports conventional desktop interaction by default, providing 2D windows with menu-driven controls for configuring topology, clustering, and comparative layouts. At any point, users may transition into an immersive mode via an explicit ``Enter VR'' operation, which rebinds the visualization to a WebXR-compatible immersive renderer while preserving analytic state.

Importantly, this transition does not represent a change of application or workflow, but rather a change of execution context. The same dataset, visual encodings, selections, and comparisons persist across desktop and immersive modes. In this sense, NeuroCave treats immersion as an optional analytical lens rather than a mandatory workspace. Such late binding of immersive rendering aligns with the broader observation that immersion is most effective when invoked selectively, in response to specific spatial reasoning needs, and exited without disrupting analytic continuity.

\paragraph{Operational perspectives and XROps.}
While systems such as NeuroCave and Uplift demonstrate the feasibility of cross-platform workflows, managing data flow, synchronization, and representation consistency across heterogeneous devices remains a central challenge. Recent work on XROps reframes immersive analytics from an operational perspective, treating analytical systems as configurable pipelines rather than monolithic applications~\cite{Jeon2025XROps}. Inspired by workflow management paradigms such as DevOps and MLOps, XROps models immersive analytics as a set of modular stages---data ingestion, transformation, rendering, and interaction---that can be dynamically composed and deployed across devices.

Crucially, this pipeline view pushes ``scalability'' upstream: if dense data must be simplified to remain interactive, the most robust place to do so is often \emph{before} it reaches a headset or display. In an XROps-style architecture, reduction steps (e.g., sampling, thresholding, region-of-interest extraction, clustering, or multi-resolution/LOD generation) can be expressed as workflow nodes that run on a central server and stream only task-relevant geometry to clients. This is consistent with long-standing VR visualization work showing that interactivity constraints strongly shape system architecture and motivate explicit multiresolution designs for large 3D data~\cite{Kreylos2003MultiresolutionVR}. For ``Hairballs to Hypotheses,'' the implication is that the engine should not merely render hairballs efficiently; it should manage a distributed workflow that produces \emph{interpretable} and \emph{interactive} representations at each device.

\paragraph{The browser as the operating system.}
Many immersive analytics systems still follow a siloed application model: a specialized VR executable with its own installation steps, device-specific runtimes, and collaboration features added later (if at all). For life science teams, this creates unnecessary friction because real analysis already happens across a mixed toolchain---for example, notebooks and scripts on a workstation, dashboards in a browser, and ad hoc collaboration with remote colleagues. A more scalable architecture treats immersive visualization as a web resource rather than a standalone program, so joining an immersive session becomes as lightweight as opening a link.

MolecularWebXR argues for this directly in the context of molecular and structural biology. By building on WebXR and standard web technologies, it targets cross-device access and low deployment barriers by avoiding dedicated installs and updates, and by supporting shared sessions that can be joined from laptops, phones, and head-mounted displays (including low-cost viewers)~\cite{CortesRodriguez2024MolecularWebXR}. The system also foregrounds synchronous collaboration through shared rooms and integrated voice communication, reinforcing that immersive visual analytics is often a group activity rather than a solo headset experience~\cite{CortesRodriguez2024MolecularWebXR}.

\paragraph{Fluid work across devices.}
DashSpace generalizes this browser-centered approach to immersive and ubiquitous analytics. Its WebXR-based workspace can be opened on desktop, handheld AR, or head-mounted VR, and it explicitly supports asymmetric collaboration where one person is immersed while another edits or monitors the shared analytic state from a conventional screen~\cite{Borowski2025DashSpace}. This matters in practice because many operations remain fastest with a mouse and keyboard (query formulation, parameter tuning, annotation), while immersive views are best reserved for tasks that benefit from spatial organization and embodied navigation. DashSpace also adopts a local-first document model that supports offline work and later synchronization, which better matches real lab and field conditions than systems that assume continuous connectivity~\cite{Borowski2025DashSpace}.

\paragraph{Hybrid input, not just hybrid displays.}
Cross-platform ecosystems are not only about where a visualization runs, but also about how interaction is distributed. Tong et al.\ study a spatial hybrid interface that couples a tracked physical desk and a conventional PC interface with a room-scale VR workspace, allowing users to move between precise 2D input and immersive spatial organization within the same sensemaking session~\cite{Tong2025SpatialHybridUI}. Their framing makes a useful point for life science visual analytics: VR offers large spatial capacity, but controller-based input can be imprecise and fatiguing, whereas PC tools are efficient but spatially constrained~\cite{Tong2025SpatialHybridUI}. Complementary designs also appear in systems that explicitly separate overview and interaction across devices; for example, Popolin Neto et al.\ integrate an immersive display with mobile devices so that navigation and global context can remain stable while detailed inspection and interaction are performed on a personal screen~\cite{Neto2015IntegratingDistinctPlatforms}. For Hairballs to Hypotheses, this suggests that the system engine should preserve analytic continuity across devices, so immersion becomes an optional view layered on the same data, state, and assistance rather than a separate application island.

\paragraph{Infrastructure-level scalability: gigapixel displays and multiresolution streaming.}
Cross-platform ecosystems also need to accommodate hardware at very different scales, from headsets to wall-sized displays. The Reality Deck exemplifies a ``hardware-first'' approach: it is a cylindrical, 360-degree immersive display with approximately gigapixel-scale resolution, enabling many collaborators to share a common, high-detail visual context~\cite{Papadopoulos2015RealityDeck}. Importantly, its architecture addresses scale not only by adding pixels, but by coupling the display to explicit level-of-detail policies: the system selects detail based on the user’s position and visual acuity, and relies on out-of-core, tile-based texture management so that only the necessary regions of extremely large imagery are resident in GPU memory at any moment~\cite{Papadopoulos2015RealityDeck}. For dense biological data, this reinforces a general architectural lesson: rendering and display capacity matter, but sustained interactivity at scale typically requires multiresolution representations and streaming strategies that are managed by the backend rather than improvised in the client.

\paragraph{Shared surfaces and a common operational picture.}
Finally, cross-platform ecosystems must support collaboration as a first-class architectural requirement. ``Shared Surfaces and Spaces'' (FIESTA) provides a co-located immersive environment where teams can create, arrange, and compare multiple visualizations by placing artifacts on virtual walls, in mid-air, or on tabletop-like surfaces~\cite{Lee2021SharedSurfacesSpaces}. While FIESTA is not a decluttering algorithm in itself, it demonstrates a practical strategy for managing analytical complexity: rather than forcing all evidence into a single dense view, collaborators externalize and spatially distribute views so that the room becomes a shared analytic memory~\cite{Lee2021SharedSurfacesSpaces}. In an ecosystem framing, such multi-user ``common operational pictures'' depend on backend services for state synchronization, provenance, and access control, ensuring that what is learned in one modality (e.g., a wall display or desktop) remains consistent when the team transitions into or out of XR.


\subsubsection{AI-Assisted Evaluation Benchmarks}
 % Development of standardized benchmark datasets and tasks (with ground-truth hypotheses, spatial cognition metrics, etc.) to evaluate AI-assisted visual analytics methods across different modalities.




% \paragraph{Forward-looking trajectory.}
A technically precise trajectory is emerging toward a closed-loop learning pipeline in which interaction logs become first-class training signals for intent/user models and guidance policies, rather than merely passive provenance~\cite{wenskovitch2019mlui,Ha2022UserModeling}.
Building on these models, learned intent inference can enable dynamic task routing across scale and abstraction---for example, prompting a ``zoom out'' to cohort-level structure during population-oriented exploration and a ``zoom in'' for local inspection when attention narrows to specific regions or entities~\cite{Wang2024GNNIntent}.
In this framing, guidance policies evolve from static recommenders into adaptive controllers over multi-view and multi-scale systems, combining proactive insight computation with action suggestion while coordinating viewpoint transitions to preserve analytic coherence~\cite{Cui2019DataSite,Li2023DiverseInteractionRecommendation}.
Critically, evaluation must incorporate explicit bias and autonomy constraints so that adaptation does not silently steer users or collapse exploration diversity; this defines an emerging design space with open problems in robustness across users and domains, transparency/provenance of recommendations, and principled mechanisms that preserve diversity while still reducing cognitive burden~\cite{Ha2022UserModeling,Ceneda2024HeuristicDualEvaluation}.

% \section{Conclusion}
%  Summarize how AI-assisted visual analytics can transform “hairballs” into actionable hypotheses in life sciences. Reiterate the two-dimensional framework (modalities × AI modes) as a unifying perspective, the unified task taxonomy, and the outlook for future research.
%  Emphasize the key takeaways and the importance of interdisciplinary efforts moving forward.

\section{Conclusion}
\label{sec:conclusion}

This STAR surveyed how AI assisted visual analytics can turn dense, unreadable biological ``hairballs'' into actionable hypotheses by shifting the burden of analysis from manual view manipulation toward mixed initiative workflows. The central takeaway is that progress in life science visualization is not driven by modality alone, or by AI alone, but by their coupling. We therefore organized the literature through a two dimensional framework, visualization modalities as the horizontal dimension and AI assistance modes as the vertical dimension, and used this model to clarify why the same dataset can feel interpretable in one setting and impossible in another. Within that framework, we proposed a unified task taxonomy spanning navigation and multiscale orientation, comparison and differentiation, selection and precision interaction, sensemaking and hypothesis development, and coordination and collaborative reasoning. This task lens makes it possible to evaluate systems by what they enable scientists to do, rather than by surface features or hardware novelty.

Across modalities, we found recurring patterns. Desktop systems remain the workhorse for precise control and reproducible analysis, but they increasingly depend on algorithmic assistance to manage scale and complexity, and on conversational and adaptive mechanisms to reduce configuration friction and support interpretation. Large displays and co located environments excel at building shared context, yet they are limited by the cost of shared reference, which motivates adaptive support for view management, linking, and personal overlays that preserve common ground. Immersive VR and AR can deliver a stereo dividend in tasks where depth, occlusion ordering, and scale matter, but they also impose a navigation tax and physiological constraints, which makes immersive AI assistance essential for guided navigation, occlusion management, stabilized selection, and attention control. The most compelling direction is not replacing one modality with another, but building cross platform ecosystems where analysts fluidly move between tools, and where assistance is preserved as part of the analytic state rather than reset at each device boundary.

Looking forward, the most important research questions are increasingly system level and interdisciplinary. Future work should pursue modality aware, task aware assistance that is transparent, auditable, and reproducible, especially when assistance becomes adaptive or generative. Evaluation needs to expand beyond time and error to include measures of scientific reasoning quality, provenance, calibration of trust, and collaborative common ground, because these outcomes determine whether hypotheses are reliable enough to drive experiments. Finally, progress will require tighter collaboration between visualization researchers, machine learning researchers, and domain scientists, not only to define meaningful tasks and datasets, but also to ensure that the next generation of intelligent visual analytics systems amplifies biological insight rather than merely accelerating interaction.


%-------------------------------------------------------------------------

\section*{Acknowledgements}
AI-assisted tools (Overleaf AI and OpenAI ChatGPT) were used for grammar correction, language polishing, limited rephrasing, and non-authoritative literature organization and summarization. All scientific content, inclusion decisions, interpretations, and conclusions were made by the authors.

%-------------------------------------------------------------------------
% bibtex
\bibliographystyle{eg-alpha-doi} 
\bibliography{BioMedVis_STAR_refs}       
\newpage

\begin{appendix}
%\appendix
\section{Methodology}
\label{app:methodology}


To ensure a comprehensive and reproducible survey of the rapidly evolving intersection between AI, visualization, and biological network analysis, we employed a semi-automated, human-in-the-loop literature review pipeline. This process leveraged custom Python scripts for data retrieval and Large Language Model (LLM) agents for semantic classification and extraction.

\subsection{Data Collection}
We queried five major academic repositories: \textbf{PubMed}, \textbf{CrossRef}, \textbf{arXiv}, \textbf{Europe PMC}, and \textbf{Semantic Scholar}. A custom Python script interfaced with the public API endpoints of these engines using a standardized set of keywords targeting the intersection of biological networks (e.g., ``genomics,'' ``connectomics,'' ``molecular dynamics'') and advanced visualization (e.g., ``immersive analytics,'' ``VR,'' ``large display'') and artificial intelligence. The initial retrieval output was aggregated into a master BibTeX file containing metadata and abstracts where available.

\subsection{LLM-Driven Classification Pipeline}
Due to the high volume of initial results, we implemented a two-stage hierarchical classification process using the OpenAI LLM API.

\paragraph{Stage 1: Assistance Mode Classification}
The master BibTeX file was processed by a sorting agent with a system prompt defining the four modes of AI assistance: \textit{Algorithmic}, \textit{Adaptive}, \textit{Conversational}, and \textit{Immersive-AI}. The agent analyzed the Title and Abstract of each entry to categorize it into one of these four modes or mark it as \textit{Off-Topic}. This stage resulted in five distinct BibTeX files.

\paragraph{Stage 2: Visualization Modality Classification}
Each of the four on-topic BibTeX files from Stage 1 was passed through a second sorting round. A separate system prompt directed the LLM to classify entries based on their display hardware and interaction environment: \textit{Desktop (2D)}, \textit{Large Display}, \textit{Virtual Reality (VR)}, \textit{Augmented/Mixed Reality (AR/XR)}, or \textit{CAVE}. This resulted in a matrix of 20 potential topic files (4 Assistance Modes $\times$ 5 Visualization Modalities) plus Off-Topic files.

\subsection{Content Extraction and Synthesis}
For papers classified as on-topic, we executed a full-text retrieval and extraction workflow:

\begin{enumerate}
    \item \textbf{Full-Text Retrieval:} Open-access manuscripts were downloaded automatically via API. Closed-access manuscripts deemed highly relevant were retrieved manually.
    \item \textbf{Semantic Extraction:} A Python script passed the full text of each paper to an OpenAI LLM agent equipped with a specific system prompt to extract structured metadata. For each paper, the agent generated a JSON object containing the Title, Authors, and five structured summary fields:
    \begin{itemize}
        \item \textbf{Core Innovation:} The primary technical contribution.
        \item \textbf{Hairball Solution:} The specific mechanism used to manage visual clutter.
        \item \textbf{Biological Utility:} The practical application in life sciences.
        \item \textbf{Key Limitation:} Constraints on scalability or usability.
        \item \textbf{STAR Integration Target:} The specific section of this report the paper belongs to.
    \end{itemize}
    \item \textbf{Relevance Scoring:} The agent assigned a numeric Relevance Score (1--5) based on the paper's alignment with the survey's goals.
\end{enumerate}

\subsection{Filtering and Final Corpus}
The classification process identified a disproportionately high volume of literature in the \textit{Desktop 2D / Algorithmic Assistance} category ($N=5,512$). To maintain a balanced scope, this specific subset was filtered to include only papers published from 2019 to present with a Relevance Score of 4 or 5. All other modalities (VR, AR, Large Display, Conversational, etc.) were included in their entirety without downsampling. Raw paper counts for each category are shown in Table \ref{tab:paper-distribution} and depicted graphically in Figure \ref{fig:paper_distribution} and symbolically in Table \ref{table:taxonomy-matrix}.

\subsection{Data and Code Availability}
To support reproducibility and further bibliometric analysis, all custom Python source code used for scraping, API interaction, and LLM-based sorting is publicly available on \href{https://github.com/iMammal/H2H-Full-STAR}{GitHub}. The complete dataset, including the raw and processed BibTeX files and the final extracted JSON corpus, has been archived on \textbf{Zenodo}.


\begin{table}[ht]
\centering
\caption{Distribution of Relevant Papers by AI Assistance Mode and Visualization Modality. (Note: Initial screening processed over 25,000 articles, with 19,465 classified as off-topic). *Original corpus of 5512 Algorithmic-Desktop papers were further filtered by date (2019-Present) and relevance score (4+ out of 5)}
\label{tab:paper-distribution}
\resizebox{\columnwidth}{!}{
\begin{tabular}{lcccccc}
\toprule
\textbf{AI Assistance} & \textbf{Desktop} & \textbf{Large Display} & \textbf{VR} & \textbf{AR/XR} & \textbf{CAVE} & \textbf{Total} \\
\midrule
Algorithmic    & 5512(97)*  & 4 & 33  & 15 & 9 & \textbf{5573(158)} \\
Adaptive       & 114 & 1 & 4   & 2  & 0 & \textbf{121} \\
Conversational & 40  & 2 & 1   & 0  & 0 & \textbf{43}  \\
Immersive-AI   & 6   & 1 & 101 & 12 & 5 & \textbf{125} \\
\midrule
\textbf{Total}            & \textbf{5672(257)} & \textbf{8} & \textbf{139} & \textbf{29} & \textbf{14} & \textbf{5959(447)} \\
\bottomrule
\end{tabular}
}
\end{table}

\end{appendix}

\end{document}
